cmake_minimum_required(VERSION 3.8.0)

project (jelly)

set(CMAKE_CXX_STANDARD 11)

message(STATUS "This is binary dir: " ${PROJECT_BINARY_DIR})
message(STATUS "This is source dir: " ${PROJECT_SOURCE_DIR})

set(PROJECT_CMAKE_DIR ${PROJECT_SOURCE_DIR}/cmake)
include(${PROJECT_CMAKE_DIR}/BuildOptions.cmake)

include_directories(${PROJECT_SOURCE_DIR}/jelly)
add_subdirectory(jelly)
