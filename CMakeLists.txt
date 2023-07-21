project(uvtest)
cmake_minimum_required(VERSION 2.8.12)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(uvtest src/main.c)
target_link_libraries(uvtest ${CMAKE_SOURCE_DIR}/lib/libuv.a)