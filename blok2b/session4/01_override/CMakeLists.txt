project(01_override VERSION 0.0.1)
juce_add_console_app(01_override PRODUCT_NAME "example")
target_sources(01_override PRIVATE main.cpp oscillator.cpp sine.cpp saw.cpp)
target_compile_definitions(01_override PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(01_override
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(01_override PRIVATE cxx_std_20)