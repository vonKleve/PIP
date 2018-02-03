#include "stdafx.h"
#include "Polygon.h"


void Polygon::operator=(vector<Point*> pp)
{
	points_ = pp;
}

Point* Polygon::at(size_t index)
{
	return points_.at(index);
}

void Polygon::set(size_t index, Point * p)
{
	points_.at(index) = p;
}

void Polygon::resize(size_t size)
{
	points_.resize(size);
}

size_t Polygon::size()
{
	return points_.size();
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Point*>>> Polygon::begin()
{
	return points_.begin();
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Point *>>> Polygon::end()
{
	return points_.end();
}
