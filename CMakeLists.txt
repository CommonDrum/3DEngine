cmake_minimum_required(VERSION 3.10)

project(3D-Engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLEW glfw spdlog::spdlog)
