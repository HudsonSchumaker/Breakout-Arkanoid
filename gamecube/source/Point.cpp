//
//  Point.cpp
//  SchumakerTeam Lab.
//  Hudson Schumaker
//

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}

void Point::move(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::translate(int d) {
	this->x += d;
	this->y += d;
}

void Point::translate(int dx, int dy) {
    this->x += dx;
    this->y += dy;
}
