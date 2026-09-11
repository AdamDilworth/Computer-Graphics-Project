/*
    main.cpp

    Main file for Computer Graphics Project
*/

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "inputManager.hpp"
#include <iostream>

int main() {
    // Initiate glfw
    if (!glfwInit()) {
        // Initialization failed
        std::cerr << "ERROR: Failed to initiate GLFW.\n";
        glfwTerminate(); // Close glfw
        std::exit(EXIT_FAILURE); // Exit program with error
    }
    
    // Create Window
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Computer Graphics Project", monitor, NULL);
    if(!window){
        // Window Creation Failed
        std::cerr << "ERROR: Failed to create window.\n";
        glfwTerminate(); // Close glfw
        std::exit(EXIT_FAILURE); // Exit program with error
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    inputManager::setupCallbacks(window);

    while (!glfwWindowShouldClose(window)) {
        // Keep running
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Close glfw before ending program
    glfwTerminate();
    return 0;
}
