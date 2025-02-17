project(01_circularBuffer VERSION 0.0.1)
juce_add_console_app(01_circularBuffer PRODUCT_NAME "01_circularBuffer")
target_sources(01_circularBuffer PRIVATE main.cpp circBuffer.cpp)
target_compile_definitions(01_circularBuffer PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(01_circularBuffer PRIVATE
        oscillators
        audio

        PUBLIC
        juce::juce_recommended_config_flags
#        juce::juce_recommended_warning_flags
)

target_compile_features(01_circularBuffer PRIVATE cxx_std_20)