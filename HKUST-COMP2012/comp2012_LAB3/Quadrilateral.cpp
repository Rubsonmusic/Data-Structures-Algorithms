#include <iostream>
#include <cmath>
#include "Quadrilateral.h"

using namespace std;

Quadrilateral::Quadrilateral(const Point2D points[], int numOfPoints):Polygon(points,numOfPoints){
	if(numOfPoints!=4){
		cout<<"Illegal, number of points should be 4"<<endl;
		if(Polygon::points!=NULL){
			delete Polygon::points;
		}
		numPoints=0;
	}
	else{
		cout<<"Initialized by Quadrilateral's other constructor"<<endl;
	}
}

Quadrilateral::~Quadrilateral(){
	cout<<"Quadrilateral Destructor"<<endl;
}

void Quadrilateral::print()const{
	//const Polygon * poly= this;
	//poly->print();
	Polygon::print();
}

Point2D Quadrilateral::center() const{
	double sumX=0; double sumY=0;
	for (int i=0; i<4; i++){
		sumX += points[i].getX();
		sumY += points[i].getY();
	}
	Point2D po(sumX/4.0, sumY/4.0);
	return po;
}

double Quadrilateral::perimeter() const{
	double per=0;
	for(int i=0; i<3; i++){
		per += points[i].distance(points[i+1]);
	}
	per+=points[3].distance(points[0]);
	return per;
}

double Quadrilateral::area() const{
	double area= (((points[0].getX()*points[1].getY() + points[1].getX()*points[2].getY() + points[2].getX()*points[3].getY()
			+ points[3].getX()*points[0].getY()) - (points[1].getX()*points[0].getY() + points[2].getX()*points[1].getY() +
					points[3].getX()*points[2].getY()+ points[0].getX()*points[3].getY()))/2.0);
	area= abs(area);
	return area;
			//math.abs((x0y1 + x1y2 + x2y3 + x3y0) - (x1y0 + x2y1 + x3y2 + x0y3))/2.0;
}
