cmake_minimum_required(VERSION 3.10)

project(Renderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")


set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)
find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)

add_subdirectory(vendor/glm)
add_subdirectory(vendor/assimp)

add_executable(${PROJECT_NAME} ${SOURCES})
if(LINUX)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLEW glfw spdlog::spdlog glm assimp) 
endif(LINUX)

if(APPLE)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} GLEW::GLEW glfw spdlog::spdlog glm "-framework OpenGL" assimp)
endif(APPLE)


