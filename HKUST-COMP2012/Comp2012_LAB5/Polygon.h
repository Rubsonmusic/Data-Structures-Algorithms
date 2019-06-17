/*
 * Polygon.h
 * The header file for the class Polygen
 */
#ifndef POLY_POLYGON_H
#define POLY_POLYGON_H

#include "Shape.h"
#include <cmath>

class Polygon : public Shape {
public:
    // outputs "Polygon constructed."
    Polygon(Point2D *points, int numPoints);

    //------your code starts from here------

    // Destructor. Function prototype here, actual code, if any, in the Polygon.cpp file.
    // outputs "Polygon destructed."

    virtual ~Polygon();



    // calculateArea(). Function prototype here, actual code, if any, in the Polygon.cpp file.
    // assume the points are arranged in the clockwise order, direct application of the Shoelace formula shown at the lab page to get the area.
    // absolute value can be derived using the abs() function, which is in the "cmath" library.
    // returns a double value.
    // outputs "Polygon::calculateArea() is Called!".

    virtual double calculateArea() const;


    // calculatePerimeter(). Function prototype here, actual code, if any, in the Polygon.cpp file.
    // returns a double value.
    // outputs "Polygon::calculatePerimeter() is Called! ".

    virtual double calculatePerimeter() const;



    //------your code ends here------



protected:
    int n_points;
    Point2D *points_ptr;
};


#endif //POLY_POLYGON_H
