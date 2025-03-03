project(2_basic_buffer_color VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(2_basic_buffer_color main.cpp)
target_include_directories(2_basic_buffer_color PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(2_basic_buffer_color PRIVATE ${OpenCV_LIBS})
