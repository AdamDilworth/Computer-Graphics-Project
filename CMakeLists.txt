cmake_minimum_required(VERSION 3.10)
project(OpenGLProject CXX C)

# Force C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the GLFW package installed on your system
find_package(glfw3 REQUIRED)

# Include directories (where to find glad/glad.h)
include_directories(include)

# Define our executable and include our source files
add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/glad.c
)

# Run command
add_custom_target(run
        COMMENT "Run main"
        COMMAND $<TARGET_FILE:OpenGLProject>
        DEPENDS OpenGLProject
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Link GLFW and your operating system's standard OpenGL library
target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
)
