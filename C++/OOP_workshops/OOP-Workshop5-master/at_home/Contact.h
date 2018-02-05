// OOP244 Workshop 5: Class with a Resource 
// File	Contact.h
// Version 1.1
// Date	2016/10/17
// Author Ricardo de oliveira Leal
// Description
// This file have a prototype for a class Contact and
// Constructors, assingment operator and function to 
// Contact.cpp
///////////////////////////////////////////////////////////
// Name			      Date		      Reason
// Ricardo leal		2016/10/17	  Workshop 5
///////////////////////////////////////////////////////////

#ifndef ICT_CONTACT_H__
#define ICT_CONTACT_h__
#include "PhoneNumber.h"

namespace ict {
	class Contact {
		char name_[41];
    PhoneNumber* phoneNumber_;
		int noPN_;
		void setEmpty();
    void copy(const Contact& copy);

	public:
		
		Contact(const Contact&);
		Contact& operator=(const Contact& C);
		Contact();
		Contact(const char* name, int np_);
		~Contact();
		void read();		
		bool isEmpty()const;
		void display()const;
	};

}

#endif