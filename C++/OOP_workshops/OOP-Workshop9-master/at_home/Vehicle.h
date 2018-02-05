// OOP244 Workshop 9: Inheritance and Virtual Functions
// File	Vehicle.h
// Version 1.0
// Date	2016/11/16
// Author Ricardo de oliveira Leal
// Description
// This file is an interface for childs classes 
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// Ricardo		2016/11/16	Workshop 9
///////////////////////////////////////////////////////////

#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_
#include <iostream>

namespace sict
{
	// complete the declaration of the class
	class Vehicle
	{
	public:
		// public members go here
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual std::ostream& display(std::ostream& ostr)const = 0;
	};
}
#endif