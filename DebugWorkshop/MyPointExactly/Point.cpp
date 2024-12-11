#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	delete _coord;
	_coord = new int[2];
	memcpy(this->_coord, other._coord, sizeof(other._coord) * 2);//2 is length
}

Point::~Point()
{
	if (_coord != nullptr) {
		delete[] _coord;
	}
}

Point& Point::operator=(const Point& other)
{
	delete _coord;
	_coord = new int[2];
	memcpy(this->_coord, other._coord, sizeof(other._coord) * 2);//2 is length
	return *this;
}

int Point::getX() const 
{ 
	return _coord[0]; 
}

int Point::getY() const
{ 
	return _coord[1]; 
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
