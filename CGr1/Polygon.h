#pragma once

#include <vector>
#include <iterator>

using std::vector;

struct UPoint 
{
	double x, y;
	UPoint(double ix, double iy) : x(ix), y(iy) {};
};

class UPolygon
{
public:
	explicit UPolygon(vector<UPoint *> pp) : points_(pp) {};
	virtual ~UPolygon() {};

	void operator=(vector<UPoint *> pp);
	UPoint* at(size_t index);
	void set(size_t index, UPoint * p);
	void resize(size_t size);
	size_t size();

	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<UPoint *>>> begin();
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<UPoint *>>> end();
private:
	vector<UPoint *> points_;
};