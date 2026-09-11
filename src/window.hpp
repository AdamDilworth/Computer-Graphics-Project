/*
    window.hpp

    Include file for window
*/

#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include "inputManager.hpp"

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

    private:
        // Width and Height
        int width, height;

        // Initialize window
        bool inititialize();

        // Sets up glfw callbacks
        void setUpCallbacks();
};
