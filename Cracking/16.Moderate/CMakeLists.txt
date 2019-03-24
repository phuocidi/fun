cmake_minimum_required(VERSION 3.5)

project (main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-Wall")

include_directories("${CMAKE_SOURCE_DIR}/header")
include_directories("${CMAKE_SOURCE_DIR}/src")


file(GLOB SOURCES
    header/*.hpp
    header/*.h
    src/*.cpp
    *.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})