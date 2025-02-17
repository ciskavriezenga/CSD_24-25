# header only files need INTERFACE
add_library(audio_header INTERFACE)
target_include_directories(audio_header INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/audiocomponent.h)

# STATIC means it will be baked into the binary (shared is also an option where that doesn't happen)
add_library(audio STATIC audioToFile.cpp bufferDebugger.cpp)
target_compile_features(audio PUBLIC cxx_std_20)
target_include_directories(audio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(audio PUBLIC audio_header juce::juce_audio_basics juce::juce_audio_devices)
