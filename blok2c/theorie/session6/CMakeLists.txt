project(session6 VERSION 0.0.1)
juce_add_console_app(session6 PRODUCT_NAME "session6")
target_sources(session6 PRIVATE main.cpp customJuceOSC.cpp callback.cpp)
target_compile_definitions(session6 PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(session6 PRIVATE
        audio

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
#        juce::juce_recommended_warning_flags
)

target_compile_features(session6 PRIVATE cxx_std_20)
