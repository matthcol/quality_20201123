/*
 * Form.h
 *
 *  Created on: 19 oct. 2020
 *      Author: Matthias
 */

#ifndef FORM_H_
#define FORM_H_

#include <string>

class Form {
public:
	Form() = default;
	Form(const std::string &name);
	// keep copy/movie constructor/assignment by default
	Form(const Form &form) = default;
	Form(Form &&form) = default;
	Form &operator=(const Form& form) = default;
	Form &operator=(Form&& form) = default;  // NB: fait bien le move sur le name

	const std::string& getName() const;
	void setName(const std::string &name);

	virtual void translate(double deltaX, double deltaY)=0;

	virtual ~Form();
private:
	std::string name; // call default constructor of class string
};

#endif /* FORM_H_ */
