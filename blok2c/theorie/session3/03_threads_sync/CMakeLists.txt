add_executable(03_threads_sync main.cpp)
target_link_libraries(03_threads_sync PUBLIC audio)
target_compile_definitions(03_threads_sync PRIVATE SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(03_threads_sync PRIVATE cxx_std_20)