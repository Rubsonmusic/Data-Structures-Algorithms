#include "Polygon.h"


Polygon::Polygon(Point2D * points, int numPoints){
	n_points=numPoints;
	points_ptr= new Point2D[numPoints];
	for(int i=0; i<numPoints; i++){
		points_ptr[i]=points[i];
	}
	std::cout<<"Constructing polygon...\n";
}

Polygon::~Polygon(){
	std::cout<<"Destructing polygon\n";
	delete [] points_ptr;
}

double Polygon::calculateArea() const{
	double sum=0;
	Point2D * r= points_ptr;										//constant pointer
	for(int i=0; i<n_points; i++){
		sum+= r[i].getX()*r[i+1].getY()  - r[i+1].getX()*r[i].getY() ;
	}
	sum+= r[n_points-1].getX()*r[0].getY()-r[n_points-1].getY()*r[0].getX();

	std::cout<<"Polygon::calculateArea() is called\n";
	return std::abs(sum);
}

double Polygon::calculatePerimeter() const {
	double perimeter=0;
	for(int i=0; i<n_points-1; i++){
		perimeter+= points_ptr[i].distance(points_ptr[i+1]);
	}
	perimeter+= points_ptr[0].distance(points_ptr[n_points-1]);

	std::cout<<"Polygon::calculatePerimeter() is called \n";
	return perimeter;
}
