#include <iostream>
#include "polygon.h"

using namespace std;

Polygon::Polygon():numPoints(0),points(NULL){
	cout<<"Initialized by Polygon's default constructor"<<endl;
}

Polygon::Polygon(const Polygon& poly):numPoints(poly.numPoints){
	points= new Point2D[numPoints];
	for(int i=0; i<numPoints; i++){
		points[i]=poly.points[i];
	}
	cout<<"Initialized by Polygon's Copy Constructor"<<endl;
}

Polygon::Polygon(const Point2D points[], int numPoints){
	this->numPoints= numPoints;
	this->points=new Point2D[numPoints];
	for(int i=0; i<numPoints; i++){
			this->points[i]=points[i];
	}
	cout<<"Initialized by Polygon's other Constructor"<<endl;
}

Polygon::~Polygon(){
	cout<<"Polygon destructor"<<endl;
	delete points;
}

void Polygon::print() const{
	if(numPoints==0){
		cout<<"Polygon is empty"<<endl; return;
	}
	cout<<"Number of Points: "<<numPoints<<endl;
	for(int i=0; i<numPoints; i++){
		points[i].print();
	}
	cout<<endl;
}
