/*
 * Point.h
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include "Form.h"

// class Point final: public Form {
class Point: public Form {
public:
	Point(); // = default;
	Point(const std::string &name, double x, double y);

	// copy mechanisms: delete or default
//	Point(const Point &other) = delete;
//	Point &operator=(const Point &other) = delete;
	Point(const Point &other) = default;
	Point &operator=(const Point &other) = default;

	// move mechanisms: =default if you remove copy versions
	Point(Point &&other) = default;
	Point &operator=(Point &&other) = default;

	// destructor
	virtual ~Point();

	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

	virtual void translate(double deltaX, double deltaY) override final;
	virtual double distance(const Point &other) const final;

private:
	double x;
	double y;
};

std::ostream &operator<<(std::ostream &out, const Point &pt);

#endif /* POINT_H_ */
