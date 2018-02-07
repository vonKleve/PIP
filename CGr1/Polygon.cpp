#include "stdafx.h"
#include "Polygon.h"


void UPolygon::operator=(vector<UPoint*> pp)
{
	points_ = pp;
}

UPoint* UPolygon::at(size_t index)
{
	return points_.at(index);
}

void UPolygon::set(size_t index, UPoint * p)
{
	points_.at(index) = p;
}

void UPolygon::resize(size_t size)
{
	points_.resize(size);
}

size_t UPolygon::size()
{
	return points_.size();
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<UPoint*>>> UPolygon::begin()
{
	return points_.begin();
}

std::_Vector_iterator<std::_Vector_val<std::_Simple_types<UPoint *>>> UPolygon::end()
{
	return points_.end();
}
