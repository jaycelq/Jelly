cmake_minimum_required(VERSION 2.8.0)

set(TARGET common)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/${TARGET}")
set(INCLUDE_DIR "${SOURCE_DIR}/include")
set(BINARY_DIR "${PROJECT_BINARY_DIR}/lib")

FILE(GLOB_RECURSE SOURCE_H ${SOURCE_DIR}/*.h)
FILE(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

set(SOURCES ${SOURCE_H} ${SOURCES})

add_library(${TARGET} ${SOURCES})

set(LIBRARY_OUTPUT_PATH ${BINARY_DIR})
