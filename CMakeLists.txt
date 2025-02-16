cmake_minimum_required(VERSION 3.31)

# Project name
project(cpp_examples)

# Specify the version of the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source directories
file(GLOB_RECURSE SOURCE_FILES "./src/*.cpp")
set(RAYLIB_PATH "./lib/external/raylib/build")

# Add the executable
link_directories(${RAYLIB_PATH})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} raylib gdi32 winmm)
target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_PATH})

message(STATUS "Current working directory: ${CMAKE_CURRENT_LIST_DIR}")