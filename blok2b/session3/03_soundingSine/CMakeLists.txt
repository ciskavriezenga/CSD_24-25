project(example VERSION 0.0.1)
juce_add_console_app(example PRODUCT_NAME "example")
target_sources(example PRIVATE main.cpp sine.cpp)
target_compile_definitions(example PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(example
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(example PRIVATE cxx_std_20)
