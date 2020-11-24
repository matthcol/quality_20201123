/*
 * Polygon.cpp
 *
 *  Created on: 20 oct. 2020
 *      Author: Matthias
 */

#include "../include/Polygon.h"
#include <algorithm>
#include <functional>

Polygon::Polygon():Form(),size(0),summits(nullptr) {
}

Polygon::Polygon(std::initializer_list<Point> init_list):Polygon("", init_list.begin(), init_list.end()) {}

Polygon::Polygon(const Polygon &other): Form(other), size(other.size) {
	this->summits = new Point[other.size];
	for (size_t i=0; i < other.size ; i++) {
		this->summits[i] = other.summits[i];
	}
}

Polygon::Polygon(Polygon &&other): Form(std::move(other)), size(other.size), summits(other.summits) {
	other.size=0;
	other.summits = nullptr;
}

Polygon::~Polygon() {
	if (summits) {
		delete[] summits;
		std::clog << "~Polygon: delete internal buffer of summits" << std::endl;
	} else {
		std::clog << "~Polygon: no internal buffer of summits to delete" << std::endl;
	}
}

size_t Polygon::getSize() const {
	return size;
}

const Point& Polygon::at(size_t pos) const{
	return summits[pos];
}

void Polygon::translate(double deltaX, double deltaY) {
	std::for_each(summits, summits+size, [deltaX,deltaY](auto& summit){summit.translate(deltaX, deltaY);});
}

std::ostream& operator <<(std::ostream &out, const Polygon &polygon) {
	out << polygon.getName() << '[';
	if (polygon.getSize()>0) {
		out << polygon.at(0);
		for (size_t i=1; i<polygon.getSize(); i++){
			out << ',' << polygon.at(i);
		}
	}
	out << ']';
	return out;
}
