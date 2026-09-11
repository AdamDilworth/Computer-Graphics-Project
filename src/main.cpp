/*
    main.cpp

    Main file for Computer Graphics Project
*/

#define GLFW_INCLUDE_NONE
#include "inputManager.hpp"
#include "window.hpp"
#include <iostream>

int main() {
    // Initialize project
    window window(512, 512, "Computer Graphics Project");
    inputManager input;

    // Link window and input manager
    window.setInputManager(&input);
    input.setWindow(&window);

    // Start project loop
    while (!window.shouldClose()) { // Runs till window is told to close
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.swapBuffers();
        glfwPollEvents(); // Process input events
    }

    // Close glfw before ending program
    glfwTerminate();
    return 0;
}
