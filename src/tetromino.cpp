/*
    tetromino.cpp

    Implementation file for tetromino
*/

#include "tetromino.hpp"

// Constructor
tetromino::tetromino(std::string shape)
    : shape(shape) {
    initializeShape(shape);
}

/*
    Initialize shape

    Helper method to extract logic from constructor
*/
void tetromino::initializeShape(std::string shape){
    if (shape == "I") {

    } else if (shape == "T") { // T shaped block

    } else if (shape == "L") { // L shaped block

    } else { // Invalid shape

    }
}

/*
    Returns shape
*/
std::string tetromino::getShape() {
    return shape;
}

/*
    Rotates shape in X direction

    direction allows "Clockwise" and "CounterClockwise"
*/
void tetromino::rotateX(std::string_view direction) {

}

/*
    Rotates shape in Y direction

    direction allows "Clockwise" and "CounterClockwise"
*/
void tetromino::rotateY(std::string_view direction) {

}

/*
    Rotates shape in Z direction

    direction allows "Clockwise" and "CounterClockwise"
*/
void tetromino::rotateZ(std::string_view direction) {

}