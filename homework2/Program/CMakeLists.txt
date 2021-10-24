cmake_minimum_required(VERSION 3.20)
project(untitled C)

# project name and language
project(task1 LANGUAGES CXX)

set(CMAKE_C_STANDARD 99)
set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        source/main.cpp
        headers/commonSquare.hpp
        headers/container.hpp
        source/container.cpp
        headers/squareMatrix.hpp
        headers/random.hpp
        source/random.cpp
        source/squareMatrix.cpp
        source/utils.cpp
        headers/utils.hpp
        headers/diagonalMatrix.hpp
        source/diagonalMatrix.cpp
        headers/triangleDownMatrix.hpp
        source/triangleDownMatrix.cpp
        source/commonSquare.cpp)

add_executable(untitled ${SOURCE_FILES})
target_link_libraries(untitled m)
