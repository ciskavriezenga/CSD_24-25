project(00_opencv_test VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(00_opencv_test main.cpp)
target_include_directories(00_opencv_test PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(00_opencv_test PRIVATE ${OpenCV_LIBS})
