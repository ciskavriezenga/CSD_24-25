project(4_basic_image_filter VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(4_basic_image_filter main.cpp)
target_include_directories(4_basic_image_filter PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(4_basic_image_filter PRIVATE ${OpenCV_LIBS})
