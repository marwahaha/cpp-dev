cmake_minimum_required(VERSION 3.1)
project(heat_conduction)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SRC_FILES "${SRC_DIR}/main.cpp")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(prog ${SRC_FILES})
target_include_directories(prog PRIVATE ${INCLUDE_DIR})

set_property(TARGET prog PROPERTY CXX_STANDARD 11)
