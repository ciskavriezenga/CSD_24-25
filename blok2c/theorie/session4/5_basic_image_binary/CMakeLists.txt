project(5_basic_image_binary VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(5_basic_image_binary main.cpp)
target_include_directories(5_basic_image_binary PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(5_basic_image_binary PRIVATE ${OpenCV_LIBS})
