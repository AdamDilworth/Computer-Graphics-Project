/*
    inputManager.cpp

    Implementation file for input manager
*/

#include "inputManager.hpp"
#include <unordered_map>
#include <print>

// Initializes key callbacks for glfw window
void inputManager::setupCallbacks(GLFWwindow* window) {
    static inputManager instance;

    glfwSetWindowUserPointer(window, &instance);

    glfwSetKeyCallback(window, inputManager::keyCallback);
}

// Returns if key has been pressed
bool inputManager::isKeyPressed(int key) {
    return keyStates[key];
}

// Allows key presses to be handled by handleKey method
void inputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Retrieve the C++ object pointer from the GLFW window
    inputManager* manager = static_cast<inputManager*>(glfwGetWindowUserPointer(window));
    
    if (manager) {
        // Forward the call to the non-static member function
        manager->handleKey(window, key, scancode, action, mods);
    }
}

// Allows handling of key presses
void inputManager::handleKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // ESC key handler
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE); // Sets window to close and terminate program
        if (logKeyHandler) // Log button press
            std::print("ESC pressed");
    }
}
