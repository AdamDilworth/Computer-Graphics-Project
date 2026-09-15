/*
    window.cpp

    Implementation file for window
*/

#include "window.hpp"
#include "inputManager.hpp"
#include <iostream>
#include <print>

// Constructor
window::window(int width, int height, std::string_view title) 
    : width(width), height(height), title(title) {
    inititialize();
}

// Initialize window
void window::inititialize() {
    // Initiate glfw
    if (!glfwInit()) {
        // Initialization failed
        std::cerr << "ERROR: Failed to initiate GLFW.\n";
        glfwTerminate(); // Close glfw
        std::exit(EXIT_FAILURE); // Exit program with error
    }
    
    // Create Window
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    GLFWwindow* win = glfwCreateWindow(width, height, "Computer Graphics Project", nullptr, nullptr);
    mainWindow = win;
    if(!win){
        // Window Creation Failed
        std::cerr << "ERROR: Failed to create window.\n";
        glfwTerminate(); // Close glfw
        std::exit(EXIT_FAILURE); // Exit program with error
    }
    glfwMakeContextCurrent(win);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwGetFramebufferSize(mainWindow, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);
    glEnable(GL_DEPTH_TEST);

    setUpCallbacks();
}

void window::swapBuffers() {
    glfwSwapBuffers(mainWindow);
}

// Returns glfw window close status
bool window::shouldClose() const {
    if (glfwWindowShouldClose(mainWindow) == GLFW_TRUE) {
        return true;
    } else {
        return false;
    }
}

// Set window close status
void window::setShouldClose(bool close) {
    if(close){
        glfwSetWindowShouldClose(mainWindow, GLFW_TRUE);
    } else {
        glfwSetWindowShouldClose(mainWindow, GLFW_FALSE);
    }
}

// Set up glfw callbacks
void window::setUpCallbacks() {
    glfwSetWindowUserPointer(mainWindow, this);

    glfwSetKeyCallback(mainWindow, keyCallback);
}

// Allows key presses to be handled by inputManager
void window::keyCallback(GLFWwindow* win, int key, int scancode, int action, int mods) {
    // Retrieve the C++ object pointer from the GLFW window
    window* self = static_cast<window*>(glfwGetWindowUserPointer(win));
    
    if (self) {
        // Forward the call to the non-static member function
        self->onKey(key, scancode, action, mods);
    }
}

// Passes key handling to inputManager class
void window::onKey(int key, int scancode, int action, int mods) {
    if (mainInput){
        mainInput->handleKey(key, scancode, action, mods);
    }
}

// Sets input manager
void window::setInputManager(inputManager* input) {
    mainInput = input;
}
