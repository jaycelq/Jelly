cmake_minimum_required(VERSION 3.3.0)

set(TARGET test)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/${TARGET})
link_directories(${PROJECT_BINARY_DIR}/lib)

FILE(GLOB TEST_SOURCE RELATIVE ${SOURCE_DIR} *.cpp)
foreach( testsourcefile ${TEST_SOURCE} )
    string( REPLACE ".cpp" "" testname ${testsourcefile})
    add_executable( ${testname} ${testsourcefile} )
    target_link_libraries(${testname} common)
endforeach( testsourcefile ${TEST_SOURCE} )
