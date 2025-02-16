cmake_minimum_required(VERSION 3.31)

# Project name
project(cpp_examples)

# Specify the version of the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source directories
file(GLOB_RECURSE SOURCE_C_FILES "./src/*.cpp")
file(GLOB_RECURSE SOURCE_H_FILES "./src/*.hpp")
set(RAYLIB_PATH "./lib/external/raylib/build")
set(GOOGLETEST_PATH "./lib/external/googletest/build")

# Add the executable
link_directories("${RAYLIB_PATH}/lib"
                 "${GOOGLETEST_PATH}/lib")

add_executable(${PROJECT_NAME} ${SOURCE_C_FILES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main raylib gdi32 winmm)
target_include_directories(${PROJECT_NAME} PRIVATE "${RAYLIB_PATH}/include"
                                                   "${GOOGLETEST_PATH}/include")

message(STATUS "Current working directory: ${CMAKE_CURRENT_LIST_DIR}")

# Testing
enable_testing()
add_test(NAME example_test COMMAND ${PROJECT_NAME})