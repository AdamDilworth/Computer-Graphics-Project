/*
    window.hpp

    Include file for window
*/

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class inputManager;

class window {
    public:
        // Constructor
        window(int width, int height, std::string_view title);

        // Returns glfw window close status
        bool shouldClose() const;

        // Returns width
        int getWidth() const;

        // Returns height
        int getHeight() const;

        // Set glfw window close status
        void setShouldClose(bool close);

        // Swap buffers
        void swapBuffers();

        // Sets input manager
        void setInputManager(inputManager* input);

    private:
        // Width and Height
        int width, height;

        // Frame buffer width and height
        int fbWidth, fbHeight;

        // Stores title
        std::string_view title;

        // GLFW window
        GLFWwindow* mainWindow = nullptr;

        // Input Manager pointer
        inputManager* mainInput = nullptr;

        // Initialize window
        void inititialize();

        // Sets up glfw callbacks
        void setUpCallbacks();

        // GLFW static callback
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        // Passes key handling to inputManager class
        void onKey(int key, int scancode, int action, int mods);
};
