project(1_basic_buffer_BW VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(1_basic_buffer_BW main.cpp)
target_include_directories(1_basic_buffer_BW PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(1_basic_buffer_BW PRIVATE ${OpenCV_LIBS})
