#ifndef POINT_H
#define POINT_H

class Point {
private:
	const int dimension;
	int* coordinates;
public:
	Point(const int dim, const int* co);
	Point(const Point& p);
	~Point();
	int getDim() const;
	double dist(const Point& p) const;
	void print() const;
	void translate(const int dim, const int diff);
};

#endif
