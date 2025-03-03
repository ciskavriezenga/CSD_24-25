project(3_basic_image_IO VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(3_basic_image_IO main.cpp)
target_include_directories(3_basic_image_IO PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(3_basic_image_IO PRIVATE ${OpenCV_LIBS})
