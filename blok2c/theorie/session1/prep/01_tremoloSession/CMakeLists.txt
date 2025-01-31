project(01_tremoloSession VERSION 0.0.1)
juce_add_console_app(01_tremoloSession PRODUCT_NAME "01_tremoloSession")
target_sources(01_tremoloSession PRIVATE main.cpp tremolo.cpp callback.cpp)
target_compile_definitions(01_tremoloSession PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(01_tremoloSession PRIVATE
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

target_compile_features(01_tremoloSession PRIVATE cxx_std_20)