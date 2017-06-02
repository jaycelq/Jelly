cmake_minimum_required(VERSION 2.8.0)

project (Jelly)

message(STATUS "This is binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "This is source dir: " ${PROJECT_SOURCE_DIR})

include_directories(common)

add_subdirectory(common)
add_subdirectory(test)
