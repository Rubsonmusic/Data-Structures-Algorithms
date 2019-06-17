/*
 * Shape.h
 * The header file for the class Shape
 */

#ifndef POLY_SHAPE_H
#define POLY_SHAPE_H

#include "Point2D.h"
#include <iostream>

class Shape {
public:

	//------your code starts from here------
    // Constructor.
    // outputs "Constructing a Shape.".
	Shape(){
		std::cout<<"Constructing a shape\n";
	}



    // Destructor, should be able to destroy the object according to its dynamic type (i.e. if it is a Circle, should be able to call the destructor of Circle).
    // outputs "Shape destructed."
	virtual ~Shape(){
		std::cout<<"Shape destructed\n";
	}




    // calculateArea()
    // Pure virtual function. Compute the area of the shape.
    // returns a double value.
	virtual double calculateArea()const = 0;




    // calculatePerimeter()
    // Pure virtual function. Compute the perimeter of the shape.
    // returns a double value.
	virtual double calculatePerimeter()const = 0;




    //------your code ends here------
};

#endif //POLY_SHAPE_H
