/*
    inputManager.hpp

    Include file for input manager
*/

#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>

class inputManager {
    public:
        // Initializes callbacks for GLFW window
        static void setupCallbacks(GLFWwindow* window);

        // Check if key is pressed
        bool isKeyPressed(int key);

    private:
        // Stores key states with true for pressed, false for unpressed
        std::unordered_map<int, bool> keyStates;

        // Logs keyhandler events in console when true
        bool logKeyHandler = true;

        // GLFW static callback
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        // Handles key inputs
        void handleKey(GLFWwindow* window, int key, int scancode, int action, int mods);
};
