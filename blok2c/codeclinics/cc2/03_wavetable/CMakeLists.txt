add_executable(03_wavetable main.cpp wavetableGenerator.cpp)
target_link_libraries(03_wavetable PUBLIC audio oscillators)
target_compile_definitions(03_wavetable PRIVATE SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(03_wavetable PRIVATE cxx_std_20)