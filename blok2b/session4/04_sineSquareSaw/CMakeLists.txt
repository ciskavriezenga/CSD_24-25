project(04_sineSquareSaw VERSION 0.0.1)
juce_add_console_app(04_sineSquareSaw PRODUCT_NAME "example")
target_sources(04_sineSquareSaw PRIVATE main.cpp audioToFile.cpp oscillator.cpp sine.cpp square.cpp callback.cpp)
target_compile_definitions(04_sineSquareSaw PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(04_sineSquareSaw
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(04_sineSquareSaw PRIVATE cxx_std_20)