/*
    inputManager.hpp

    Include file for input manager
*/

#pragma once
#include <unordered_map>

class window;

class inputManager {
    public:
        // Constructor
        inputManager();

        // Check if key is pressed
        bool isKeyPressed(int key);

        // Handles key inputs
        void handleKey(int key, int scancode, int action, int mods);

        // Set window
        void setWindow(window* window);

    private:
        // Stores key states with true for pressed, false for unpressed
        std::unordered_map<int, bool> keyStates;

        // Logs keyhandler events in console when true
        bool logKeyHandler = true;

        // Holds window pointer
        window* mainWindow = nullptr;
};
