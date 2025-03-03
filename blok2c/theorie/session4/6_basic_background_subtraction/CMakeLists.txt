project(6_basic_background_subtraction VERSION 0.0.1)
find_package(OpenCV REQUIRED)

add_executable(6_basic_background_subtraction main.cpp BGModelCreator.cpp bgSubtractor.cpp bgSubtractorAverage.cpp bgSubtractorSD.cpp)
target_include_directories(6_basic_background_subtraction PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(6_basic_background_subtraction PRIVATE ${OpenCV_LIBS})
