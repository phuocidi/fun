#! /usr/bin/bash
CPPBUILD=$(pwd)/build
CPPBIN=$(pwd)/bin
if [[ ( -d $CPPBUILD ) && ( -d $CPPBIN ) ]];  
  then rm -rf bin build && echo && echo "Deleting bin and build directory";
fi

mkdir bin build && echo && echo "Created bin and build directory"

echo "cmake_minimum_required(VERSION 3.0)

project($1)

# Set the output folder where your program will be created

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(main main.cpp)" > CMakeLists.txt

#cmake -H. -Bbuild && cmake --build build && ./bin