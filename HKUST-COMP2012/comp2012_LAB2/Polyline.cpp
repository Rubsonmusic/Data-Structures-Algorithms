#include <iostream>
#include "Polyline.h"

using namespace std;

Polyline::Polyline(){
	currSize=0; points=NULL;
}

Polyline::Polyline(const Point& p1, const Point& p2){
	if(p1.getDim()!=p2.getDim()){
		cout<<"Error: Dimensions of the points in a polyline must be the same";
		currSize=0; points=NULL;
	}
	else {
		currSize=2;
		points= new const Point*[2];
		//points[0]= new Point(p1); points[1]= new Point(p2);
		points[0]= &p1; points[1]= &p2;
	}
}

Polyline::Polyline(const Polyline& polyline){
	currSize= polyline.currSize;
	points= new const Point*[currSize];
	for (int i=0; i<currSize; i++){
		//points[i]= new Point(polyline.points[i]);
		points[i]= polyline.points[i];
	}
}

Polyline::~Polyline(){
	delete points;
}

void Polyline::addPoint(const Point&p){
	if(currSize!=0){
		if((p.getDim() != points[0]->getDim())){
		cout<<"Dimensions of Points in a Polyline must be the same";
		return;
		}
	}
	currSize++;
	const Point** tempPoints= points;
	points= new const Point*[currSize];
	for(int i=0; i<currSize-1; i++){
		points[i]=tempPoints[i];
	}
	points[currSize-1]=&p;
	delete tempPoints;
}

void Polyline::print() const{
	for(int i=0; i<currSize; i++){
		points[i]->print();
		cout<<endl;
	}
}

double Polyline::getLength() const{
	double sum=0;
	for(int i=0; i<currSize-1; i++){
		sum+=points[i]->dist(*(points[i+1]));
	}
	return sum;
}
