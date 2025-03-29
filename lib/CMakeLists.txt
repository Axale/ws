add_library(http http.c)
target_include_directories(http PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_library(net net.c)
target_include_directories(net PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})