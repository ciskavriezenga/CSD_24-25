project(liblo_juce VERSION 0.0.1)

find_library(LIBLO_LIBRARY NAMES lo)
find_path(LIBLO_INCLUDE_DIR lo/lo.h)

juce_add_console_app(liblo_juce PRODUCT_NAME "liblo_juce")
target_sources(liblo_juce PRIVATE main.cpp callback.cpp osc_server.h osc.cpp)
target_compile_definitions(liblo_juce PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(liblo_juce PRIVATE ${LIBLO_INCLUDE_DIR})
target_link_libraries(liblo_juce PRIVATE
        audio
        ${LIBLO_LIBRARY}
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(liblo_juce PRIVATE cxx_std_20)