#pragma once

#include <vector>
#include <iterator>

using std::vector;

struct Point 
{
	double x, y;
	Point(double ix, double iy) : x(ix), y(iy) {};
};

class Polygon
{
public:
	explicit Polygon(vector<Point *> pp) : points_(pp) {};
	virtual ~Polygon() {};

	void operator=(vector<Point *> pp);
	Point* at(size_t index);
	void set(size_t index, Point * p);
	void resize(size_t size);
	size_t size();

	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Point *>>> begin();
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Point *>>> end();
private:
	vector<Point *> points_;
};