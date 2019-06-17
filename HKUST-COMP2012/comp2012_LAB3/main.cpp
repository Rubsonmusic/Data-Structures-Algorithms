/*
 * main.cpp
 *
 */

#include <iostream>
#include "Point2D.h"
#include "Quadrilateral.h"
using namespace std;

int main()
{
	cout << "Polygon1:" << endl;
	Polygon *poly1 = new Polygon;
	poly1->print();
	delete poly1;
	cout << endl;

	cout << "Polygon2:" << endl;
	Point2D points1[4] = {Point2D(0, 0), Point2D(1, 0) , Point2D(1,1), Point2D(0, 1)};
	Polygon *poly2 = new Polygon(points1, 4);
	poly2->print();
	cout << endl;

	cout << "Quadrilateral1:" << endl;
	points1[0] = Point2D(-1,-1);
	Quadrilateral *quad1 = new Quadrilateral(points1, 4); // Initialized by the parameterized constructor
	quad1->print();
	cout<< "Quadrilateral's centre: ";quad1->center().print();cout<<endl;
	cout<< "Quadrilateral's perimeter:"<< quad1->perimeter();cout<<endl;
	cout<< "Quadrilateral's area: "<<quad1->area()<<endl;

	delete quad1;
	cout << endl;

	cout << "Polygon2:" << endl;
	poly2->print();
	delete poly2;
	cout << endl;


 	cout << "Quadrilaterale2:" << endl;
	Point2D points2[4] = {Point2D(0, 0), Point2D(1, 1), Point2D(2, 0), Point2D(1, 2)};
	Quadrilateral *quad2 = new Quadrilateral(points2, 4); // Initialized by the parameterized constructor
	quad2->print();
	cout<< "Quadrilateral's centre: ";quad2->center().print();cout<<endl;
	cout<< "Quadrilateral's perimeter:"<< quad2->perimeter();cout<<endl;
	cout<< "Quadrilateral's area: "<<quad2->area()<<endl;
	delete quad2;
	cout << endl;

	cout << "Quadrilateral3:" << endl;
	Point2D points3[2] = {Point2D(0, 0), Point2D(1, 1)};
	Quadrilateral *quad3 = new Quadrilateral(points3, 2); // Initialized by the parameterized constructor
	delete quad3;

	return 0;
}
