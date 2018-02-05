// OOP244 Workshop 9: Inheritance and Virtual Functions
// File	SportCar.h
// Version 1.0
// Date	2016/11/16
// Author Ricardo de oliveira Leal
// Description
// This file have implemented all prototypes for 
// SportCar.cpp
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// Ricardo		2016/11/16	Workshop 9
///////////////////////////////////////////////////////////

#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include "Car.h"

namespace sict
{
	// complete the declaration of the class
	class SportCar : public Car
	{
	private:
		// private members go here
    int noOfPassagers_;

	public:
		// public members go here
    SportCar();
    SportCar(int maxSpeed, int numPass);    
		// pure virtual members from base class go here
    void accelerate();
    void brake();
    std::ostream& display(std::ostream& ostr)const;
	};
}
#endif