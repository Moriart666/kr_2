cmake_minimum_required(VERSION 3.10)

project(VK_Algos)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCES
    lib.cpp
    test.cpp
)

add_executable(test ${SOURCES})

target_link_libraries(test ${GTEST_LIBRARIES} pthread)