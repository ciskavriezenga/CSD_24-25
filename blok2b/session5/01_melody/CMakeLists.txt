project(session5_melody VERSION 0.0.1)
juce_add_console_app(session5_melody PRODUCT_NAME "example")
target_sources(session5_melody PRIVATE main.cpp square.cpp melody.cpp)
target_compile_definitions(session5_melody PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR=".")

target_link_libraries(session5_melody
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(session5_melody PRIVATE cxx_std_20)
