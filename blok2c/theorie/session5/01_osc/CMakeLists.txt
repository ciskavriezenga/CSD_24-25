project(01_osc VERSION 0.0.1)

#find_package(LIBLO_FOUND REQUIRED)

message(${CMAKE_SOURCE_DIR})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})

find_package(liblo REQUIRED MODULE)
include_directories(${LIBLO_INCLUDE_DIRS})

add_executable(osc_server osc_server.cpp osc.cpp)
target_include_directories(osc_server PRIVATE ${LIBLO_INCLUDE_DIRS})
target_link_libraries(osc_server PRIVATE ${LIBLO_LIBRARIES})

add_executable(osc_client osc_client.cpp)
target_include_directories(osc_client PRIVATE ${LIBLO_INCLUDE_DIRS})
target_link_libraries(osc_client PRIVATE ${LIBLO_LIBRARIES})
