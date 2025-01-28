/**********************************************************************
*          Copyright (c) 2022, Hogeschool voor de Kunsten Utrecht
*                      Utrecht, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : jack_module.h
*  System name   : jack_module
*
*  Description   : C++ abstraction for JACK Audio Connection Kit
*
*
*  Authors       : Marc Groenewegen,
*                  Wouter Ensink,
*                  Daan Schrier
*  E-mails       : marc.groenewegen@hku.nl,
*                  wouter.ensink@student.hku.nl,
*                  daan.schrier@student.hku.nl
*
**********************************************************************/


#pragma once

#include <jack/jack.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <unistd.h>
#include <vector>

/// This struct contains pointers to the input and output buffers provided by Jack, as well as the
/// number of channels in each buffer and the number of frames.
struct AudioBuffer {
    const float** inputChannels;
    float** outputChannels;
    const int numInputChannels;
    const int numOutputChannels;
    const int numFrames;
};



/// Base class for your own audio callback. Make a subclass of this and register it with a `JackModule` instance.
class AudioCallback {
public:
    /// This function is called before process, so you can prepare any of your effects.
    virtual void prepare (int sampleRate) {}

    /// This function is called when Jack requests new audio data. An instance of `AudioBuffer` is passed as an argument, which
    /// can be used to collect incoming audio and send outgoing sample data.
    virtual void process (AudioBuffer buffer) {}
};



/// Jack Client. Make an instance of this (only one per program) and provide it with a reference to your
/// `AudioCallback` subclass via its constructor. After that call `init()` to start the Jack session.
class JackModule {
public:
    explicit JackModule (AudioCallback& audioCallback) : callback (audioCallback) {}

    ~JackModule() {
        end();
    }

    /// Call `init()` and pass the number of inputs and outputs. If no other arguments are passed the defaults
    /// mentioned below will be passed automatically. It is possible to manually enter arguments for `clientName`
    /// `inputClient` and `outputClient`.
    void init (int numInputs,
               int numOutputs,
               std::string_view clientName = "JackModule",
               std::string_view inputClient = "system",
               std::string_view outputClient = "system") {
        setNumInputChannels (numInputs);
        setNumOutputChannels (numOutputs);

        openJackClient (clientName);
        registerJackCallbacks();

        registerInputPorts();
        registerOutputPorts();

        allocateBuffers();

        /*
         *  as Jack will start calling process() as soon as the client is
         *  activated, all preparations must be done prior to that. Therefore
         *  prepareCallback() must be (just) before activateJackClient
         */
        prepareCallback();

        activateJackClient();

        connectInputs (inputClient);
        connectOutputs (outputClient);
    }

    /// Returns the sampling rate at which Jack is running. Only call this after `init()` has been called
    int getSampleRate() const {
        return static_cast<int> (jack_get_sample_rate (client));
    }

private:
    using UniquePortsPtr = std::unique_ptr<const char*, void (*) (const char**)>;

    static_assert (std::is_same_v<jack_default_audio_sample_t, float>,
                   "this code assumes the jack audio sample type to be float, which is not the case if this assert fails");

    AudioCallback& callback;
    jack_client_t* client = nullptr;

    std::vector<jack_port_t*> inputPorts;
    std::vector<jack_port_t*> outputPorts;
    std::vector<float*> inputBuffers;
    std::vector<float*> outputBuffers;

    int numInputChannels = 2;
    int numOutputChannels = 2;
    static constexpr auto MAX_INPUT_CHANNELS = 2;
    static constexpr auto MAX_OUTPUT_CHANNELS = 2;

    static int jackProcessCallback (jack_nframes_t numFrames, void* self) {
        return (reinterpret_cast<JackModule*> (self))->onProcess (numFrames);
    }

    int onProcess (jack_nframes_t numFrames) {
        for (int channel = 0; channel < numInputChannels; ++channel) {
            inputBuffers[channel] = reinterpret_cast<float*> (jack_port_get_buffer (inputPorts[channel], numFrames));
        }

        for (int channel = 0; channel < numOutputChannels; ++channel) {
            outputBuffers[channel] = reinterpret_cast<float*> (jack_port_get_buffer (outputPorts[channel], numFrames));
        }

        const auto buffer = AudioBuffer {
            .inputChannels = const_cast<const float**> (inputBuffers.data()),
            .outputChannels = outputBuffers.data(),
            .numInputChannels = static_cast<int> (inputBuffers.size()),
            .numOutputChannels = static_cast<int> (outputBuffers.size()),
            .numFrames = static_cast<int> (numFrames),
        };
        callback.process (buffer);

        return 0;
    }

    void activateJackClient() const {
        if (jack_activate (client)) {
            throw std::runtime_error { "Cannot activate client" };
        }
    }

    static int countPorts (const char** ports) {
        auto numPorts = 0;
        while (ports[numPorts])
            ++numPorts;
        return numPorts;
    }

    static auto makePortsPtr (const char** ports) -> UniquePortsPtr {
        return {
            ports,
            [] (auto** p) { free (p); }
        };
    }

    auto findPorts (std::string_view clientName, uint64_t flags) -> UniquePortsPtr {
        if (auto ports = makePortsPtr (jack_get_ports (client, clientName.data(), nullptr, flags))) {
            return ports;
        }

        throw std::runtime_error {
            "Cannot find capture ports associated with " + std::string { clientName }
        };
    }

    void setNumInputChannels (int n) {
        if (n > MAX_INPUT_CHANNELS || n < 0) {
            throw std::runtime_error { "Invalid number of input channels" };
        }
        numInputChannels = n;
    }

    void setNumOutputChannels (int n) {
        if (n > MAX_OUTPUT_CHANNELS || n < 0) {
            throw std::runtime_error { "Invalid number of output channels" };
        }
        numOutputChannels = n;
    }

    void connectInputs (std::string_view inputClient) {
        if (numInputChannels > 0) {
            auto ports = findPorts (inputClient, JackPortIsOutput);

            if (countPorts (ports.get()) < numInputChannels) {
                throw std::runtime_error { "Not enough Jack ports for the number of requested input channels" };
            }

            for (int channel = 0; channel < numInputChannels; ++channel) {
                if (jack_connect (client, ports.get()[channel], jack_port_name (inputPorts[channel]))) {
                    throw std::runtime_error { "Cannot connect input ports" };
                }
            }
        }
    }

    void connectOutputs (std::string_view outputClient) {
        if (numOutputChannels > 0) {
            auto ports = findPorts (outputClient, JackPortIsInput);

            if (countPorts (ports.get()) < numOutputChannels) {
                throw std::runtime_error { "Not enough Jack ports for the number of requested output channels" };
            }

            for (int channel = 0; channel < numOutputChannels; ++channel) {
                if (jack_connect (client, jack_port_name (outputPorts[channel]), ports.get()[channel])) {
                    throw std::runtime_error { "Cannot connect output ports" };
                }
            }
        }
    }

    void registerInputPorts() {
        inputPorts.clear();
        for (int channel = 0; channel < numInputChannels; ++channel) {
            const auto name = "input_" + std::to_string (channel + 1);
            const auto port = jack_port_register (client, name.c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
            inputPorts.push_back (port);
        }
    }

    void registerOutputPorts() {
        outputPorts.clear();
        for (int channel = 0; channel < numOutputChannels; ++channel) {
            const auto name = "output_" + std::to_string (channel + 1);
            const auto port = jack_port_register (client, name.c_str(), JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
            outputPorts.push_back (port);
        }
    }

    void openJackClient (std::string_view clientName) {
        client = jack_client_open (clientName.data(), JackNoStartServer, nullptr);

        if (client == nullptr) {
            throw std::runtime_error { "JACK server not running" };
        }
    }

    void registerJackCallbacks() const {
        jack_on_shutdown (client, onJackShutdown, nullptr);
        jack_set_process_callback (client, jackProcessCallback, (void*) this);
    }

    void allocateBuffers() {
        inputBuffers.resize (numInputChannels);
        outputBuffers.resize (numOutputChannels);
    }

    void prepareCallback() {
        callback.prepare (getSampleRate());
    }

    void end() {
        jack_deactivate (client);

        for (auto* port : inputPorts)
            jack_port_disconnect (client, port);

        for (auto* port : outputPorts)
            jack_port_disconnect (client, port);
    }

    static void onJackShutdown (void*) {
        exit (1);
    }
};
