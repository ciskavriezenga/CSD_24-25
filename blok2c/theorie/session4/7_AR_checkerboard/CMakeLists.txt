project(7_AR_checkerboard VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(7_AR_checkerboard main.cpp axes.cpp cameraCalibrator.cpp cube.cpp drawObject.cpp )
target_include_directories(7_AR_checkerboard PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(7_AR_checkerboard PRIVATE ${OpenCV_LIBS})
