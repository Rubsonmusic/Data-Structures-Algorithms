#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;

Point::Point(const int dim, const int* co):dimension(dim){
	coordinates= new int[dim];
	for(int i=0; i<dim; i++){
			*(i+coordinates)= *(i+co);
		}
}

Point::Point(const Point& p):dimension(p.dimension){
	coordinates= new int[p.dimension];
	for(int i=0; i<p.dimension; i++){
		*(i+coordinates)= *(i + p.coordinates);
	}
}

int Point::getDim() const{
	return dimension;
}

void Point::print() const{
	cout<<'(';
	for(int i=0;i<dimension-1;i++){
		cout<<*(i+coordinates)<<',';
	}
	cout<<*(dimension-1 + coordinates)<<')';
}

Point::~Point(){
	delete coordinates;
}

double Point::dist(const Point& p) const{
	if(p.dimension!=dimension){
		cout<<"Error: Dimensions of two points do not match.\n";
		return 0;
	}
	double sumsqr=0;
	for(int i=0; i<dimension; i++){
		sumsqr= sumsqr + (coordinates[i]-p.coordinates[i])*(coordinates[i]-p.coordinates[i]);
	}
	return sqrt(sumsqr);
}

void Point::translate(int dim, int diff){
	if(dim>dimension){cout<<"Error: Dimension is invalid\n"; return;}
	coordinates[dim-1]+= diff;
}
