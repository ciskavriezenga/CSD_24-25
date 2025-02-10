project(02_override_callFromBase VERSION 0.0.1)
juce_add_console_app(02_override_callFromBase PRODUCT_NAME "example")
target_sources(02_override_callFromBase PRIVATE main.cpp oscillator.cpp sine.cpp)
target_compile_definitions(02_override_callFromBase PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(02_override_callFromBase
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(02_override_callFromBase PRIVATE cxx_std_20)