/*
    inputManager.cpp

    Implementation file for input manager
*/

#include "inputManager.hpp"
#include "window.hpp"
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <print>

// Constructor
inputManager::inputManager() {

}

// Returns if key has been pressed
bool inputManager::isKeyPressed(int key) {
    return keyStates[key];
}

// Allows handling of key presses
void inputManager::handleKey(int key, int scancode, int action, int mods) {
    // ESC key handler
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        mainWindow->setShouldClose(true);
        if (logKeyHandler) // Log button press
            std::println("ESC pressed");
    }
}

// Sets window pointer
void inputManager::setWindow(window* window) {
    mainWindow = window;
}
