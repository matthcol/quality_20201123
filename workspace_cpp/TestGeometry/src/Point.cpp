/*
 * Point.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include "../include/Point.h"

#include <cmath>

//Point::Point(): Form(), x(0.0), y(0.0){}
Point::Point(): Point("",0.0, 0.0){}


Point::Point(const std::string &name, double x, double y): Form(name), x(x), y(y)
{
}

//Point::Point(Point &&other):Form(std:move(other)), x(other.x), y(other.y) {
//	other.x = 0.0;
//	other.y = 0.0;
//}

Point::~Point(){}

double Point::getX() const {
	return x;
}

void Point::setX(double x) {
	this->x = x;
}

double Point::getY() const {
	return y;
}

void Point::setY(double y) {
	this->y = y;
}

void Point::translate(double deltaX, double deltaY) {
	this->x += deltaX;
	this->y += deltaY;
}

double Point::distance(const Point &other) const {
	return std::hypot(this->x - other.x, this->y - other.y);
}

std::ostream &operator<<(std::ostream &out, const Point &pt) {
	return out << pt.getName() << '(' << pt.getX() << ',' << pt.getY() << ')';
}


