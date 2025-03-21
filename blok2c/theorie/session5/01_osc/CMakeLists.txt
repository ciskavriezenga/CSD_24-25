project(01_osc VERSION 0.0.1)

find_library(LIBLO_LIBRARY NAMES lo)
find_path(LIBLO_INCLUDE_DIR lo/lo.h)

add_executable(osc_server osc_server.cpp osc.cpp)
target_include_directories(osc_server PRIVATE ${LIBLO_INCLUDE_DIR})
target_link_libraries(osc_server PRIVATE ${LIBLO_LIBRARY})

add_executable(osc_client osc_client.cpp)
target_include_directories(osc_client PRIVATE ${LIBLO_INCLUDE_DIR})
target_link_libraries(osc_client PRIVATE ${LIBLO_LIBRARY})
