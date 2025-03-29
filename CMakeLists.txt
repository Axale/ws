cmake_minimum_required(VERSION 3.10.0)
project(webserver VERSION 0.1.0 LANGUAGES C)

add_subdirectory(lib)
add_executable(webserver main.c)

target_link_directories(webserver PRIVATE http)
target_link_directories(webserver PRIVATE net)
