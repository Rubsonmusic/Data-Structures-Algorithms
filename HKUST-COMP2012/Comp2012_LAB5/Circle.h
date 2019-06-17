/*
 * Circle.h
 * The header file for the class Circle
 */

#ifndef POLY_CIRCLE_H
#define POLY_CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
public:
    // Constructor
    // outputs "Circle constructed."
    Circle(Point2D point, double radius_length);

    //------your code starts from here------

    // Destructor
    // outputs "Circle destructed.".
    ~Circle();



    // calculateArea(). Function prototype here, actual code, if any, in the Circle.cpp file.
    // returns a double value.
    // outputs "Circle::calculateArea() is Called! ".

    virtual double calculateArea() const;



    // calculatePerimeter(). Function prototype here, actual code, if any, in the Circle.cpp file.
    // returns a double value.
    // Print out "Circle::calculatePerimeter() is Called! ".

    virtual double calculatePerimeter() const;



    //------your code ends here------

protected:
    double radius;
    Point2D center;
};


#endif //POLY_CIRCLE_H
