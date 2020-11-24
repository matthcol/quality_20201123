/*
 * Form.cpp
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#include "../include/Form.h"
#include <iostream>

Form::Form(const std::string &name):name(name) // list initialization
{
}

Form::~Form() {
}

const std::string& Form::getName() const {
	return name;
}

void Form::setName(const std::string &name) {
	this->name = name;
}

void Form::translate(double deltaX, double deltaY) {
}


