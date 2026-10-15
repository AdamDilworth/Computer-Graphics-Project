/*
    tetromino.hpp

    Include file for tetromino
*/

#pragma once
#include <string>

class tetromino {
    public:
        // Constructor
        tetromino(std::string shape);
        
        // Returns shape type
        std::string getShape();

        /*
            Rotates shape in X direction

            direction allows "Clockwise" and "CounterClockwise"
        */
        void rotateX(std::string_view direction);

        /*
            Rotates shape in Y direction

            direction allows "Clockwise" and "CounterClockwise"
        */
        void rotateY(std::string_view direction);

        /*
            Rotates shape in Z direction

            direction allows "Clockwise" and "CounterClockwise"
        */
        void rotateZ(std::string_view direction);

    private:
        // Holds shape type
        std::string shape;

        /*
            Initialize shape

            Helper method to extract logic from constructor
        */
        void initializeShape(std::string shape);
};
