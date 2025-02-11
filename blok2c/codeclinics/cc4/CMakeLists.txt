project(Filters VERSION 0.0.1)
juce_add_console_app(Filters PRODUCT_NAME "Filters")
target_sources(Filters PRIVATE main.cpp)
target_compile_definitions(Filters PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(Filters
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(Filters PRIVATE cxx_std_20)
