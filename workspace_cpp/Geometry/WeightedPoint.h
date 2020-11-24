/*
 * WeightedPoint.h
 *
 *  Created on: 20 oct. 2020
 *      Author: Matthias
 */

#ifndef WEIGHTEDPOINT_H_
#define WEIGHTEDPOINT_H_

#include "Point.h"

class WeightedPoint: public Point { // Error if parent class is final
public:
	WeightedPoint();
	virtual ~WeightedPoint();

	// error if method is final in parent class:
	// virtual void translate(double deltaX, double deltaY) override {};

	// TODO: manage weight attribute
};

#endif /* WEIGHTEDPOINT_H_ */
