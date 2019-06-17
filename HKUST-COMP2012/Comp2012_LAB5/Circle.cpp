#include "Circle.h"

Circle::Circle(Point2D point, double radius_length):radius(radius_length), center(point){
	std::cout<<"Constructing circle...\n";
}

Circle::~Circle(){
	std::cout<<"Destructing circle...\n";
}

double Circle::calculateArea() const{
	std::cout<<"Circle::calculateArea() is called \n";
	return M_PI*radius*radius;
}

double Circle::calculatePerimeter() const{
	std::cout<<"Circle::calculateArea() is called \n";
	return 2*M_PI*radius;
}
