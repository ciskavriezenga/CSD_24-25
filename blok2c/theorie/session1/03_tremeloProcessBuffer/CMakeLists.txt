project(03_tremoloProcessBuffer VERSION 0.0.1)
juce_add_console_app(03_tremoloProcessBuffer PRODUCT_NAME "03_tremoloProcessBuffer")
target_sources(03_tremoloProcessBuffer PRIVATE main.cpp tremolo.cpp callback.cpp)
target_compile_definitions(03_tremoloProcessBuffer PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(03_tremoloProcessBuffer PRIVATE
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


target_compile_features(03_tremoloProcessBuffer PRIVATE cxx_std_20)