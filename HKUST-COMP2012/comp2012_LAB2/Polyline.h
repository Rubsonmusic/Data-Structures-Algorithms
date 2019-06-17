#include "Point.h"
#ifndef POLYLINE_H
#define POLYLINE_H

class Polyline {
private:
	int currSize;
	const Point** points;
public:
	Polyline();
	Polyline(const Point& p1, const Point& p2);
	Polyline(const Polyline& polyline);
	~Polyline();
	double getLength() const;
	void print() const;
	void addPoint(const Point& p);
};

#endif
