/*
 * Polygon.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Matthias
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Point.h"
#include "Form.h"
#include <string>
#include <iostream>

class Polygon: public Form {
public:
	template<class PointIterator>
	Polygon(const std::string &name, PointIterator first, PointIterator last):
		Form(name),
		size(std::distance(first, last))
	{
		summits = new Point[size];
		for (auto it = summits ; first != last; ++first, ++it) {
			*it = *first;
		}
	}

	Polygon();
	Polygon(std::initializer_list<Point> init_list);
	virtual ~Polygon();

	Polygon(const Polygon &other); // = default; // deep copy of sommets
	Polygon(Polygon &&other); // = default;		// move of sommets et reset sommets/size other

	virtual void translate(double deltaX, double deltaY);
	size_t getSize() const;
	const Point &at(size_t pos) const;

private:
	size_t size;
	Point *summits;
};

std::ostream &operator<<(std::ostream &out, const Polygon& polygon);

#endif /* POLYGON_H_ */
