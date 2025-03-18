cmake_minimum_required(VERSION 3.10)
project(GLFWProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/libraries/include)

# Link directories
link_directories(${PROJECT_SOURCE_DIR}/libraries/lib)

# Copy the shaders folder to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# Add GLAD implementation
add_library(glad STATIC src/glad.c)

# Add executable
add_executable(GLFWProject 
    src/main.cpp 
    src/shader_program.cpp 
    src/window.cpp
    src/shader.cpp
    src/VAO.cpp
    src/VBO.cpp
    src/VAP.cpp
    src/EBO.cpp
    src/texture.cpp
    src/stb_image.cpp
)

# Link GLFW
target_link_libraries(GLFWProject glfw3)

# Link GLAD and GLFW
target_link_libraries(GLFWProject glad glfw)

# On Linux, link against X11 and OpenGL
if (UNIX AND NOT APPLE)
    target_link_libraries(GLFWProject X11)
    target_link_libraries(GLFWProject GL)
    target_link_libraries(GLFWProject Xrandr)
    target_link_libraries(GLFWProject Xi)
    target_link_libraries(GLFWProject Xxf86vm)
    target_link_libraries(GLFWProject Xinerama)
    target_link_libraries(GLFWProject Xcursor)
    target_link_libraries(GLFWProject pthread)
    target_link_libraries(GLFWProject dl)
endif()