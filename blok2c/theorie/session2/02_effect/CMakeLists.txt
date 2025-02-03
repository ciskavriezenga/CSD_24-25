project(02_effect VERSION 0.0.1)
juce_add_console_app(02_effect PRODUCT_NAME "02_effect")
target_sources(02_effect PRIVATE main.cpp callback.cpp effect.cpp tremolo.cpp delay.cpp)
target_compile_definitions(02_effect PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(02_effect PRIVATE
        oscillators
        audio

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(02_effect PRIVATE cxx_std_20)