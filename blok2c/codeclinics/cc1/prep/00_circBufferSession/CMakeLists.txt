project(00_circBufferSession VERSION 0.0.1)
juce_add_console_app(00_circBufferSession PRODUCT_NAME "00_circBufferSession")
target_sources(00_circBufferSession PRIVATE main.cpp circBuffer.cpp)
target_compile_definitions(00_circBufferSession PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(00_circBufferSession PRIVATE
        oscillators
        audio

        PUBLIC
        juce::juce_recommended_config_flags
#        juce::juce_recommended_warning_flags
)

target_compile_features(00_circBufferSession PRIVATE cxx_std_20)