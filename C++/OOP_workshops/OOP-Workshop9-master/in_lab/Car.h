// OOP244 Workshop 9: Inheritance and Virtual Functions
// File	Car.h
// Version 1.0
// Date	2016/11/16
// Author Ricardo de oliveira Leal
// Description
// This file have implemented all prototypes in 
// Car.cpp
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// Ricardo		2016/11/16	Workshop 9
///////////////////////////////////////////////////////////

#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include "Vehicle.h"

namespace sict
{
	// complete the declaration of the class
  class Car : public Vehicle
	{
	private:
		// private members go here
    int speed_;
    int maxSpeed_;

	protected:
		// protected members go here
    void speed(int value);
    int maxSpeed()const;

	public:
		// public members go here
    /*Car();*/
    Car(int maxSpeed = 100);
    int speed()const;
	};
}

#endif