cmake_minimum_required(VERSION 3.1)
project(heat_conduction)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SRC_FILES 
			${SRC_DIR}/main.cpp
			${SRC_DIR}/draw.cpp
			${SRC_DIR}/shader.cpp)
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLAD_DIR "${LIB_DIR}/glad")

set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

# we act like this for time economy:
# just set the library directory for 
# referring to local CMakeLists.txt
add_subdirectory("${GLFW_DIR}")

add_library("glad" "${GLAD_DIR}/src/glad.c")

add_executable(prog ${SRC_FILES})

target_link_libraries(prog "glfw" "${GLFW_LIBRARIES}")
target_link_libraries(prog "glad" "${CMAKE_DL_LIBS}")

target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(prog PRIVATE "${GLFW_DIR}/include")
target_include_directories(prog PRIVATE "${INCLUDE_DIR}")
target_include_directories(prog PRIVATE "${GLAD_DIR}/include")

target_compile_definitions(prog PRIVATE "GLFW_INCLUDE_NONE")

set_property(TARGET prog PROPERTY CXX_STANDARD 11)
