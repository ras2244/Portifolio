#ifndef ICT_CONTACT_H__
#define ICT_CONTACT_h__
#include "PhoneNumber.h"

namespace ict {
	class Contact {
		char name_[41];
    PhoneNumber* phoneNumber_;
		int noPN_;
		void setEmpty();

	public:

		Contact();
		Contact(const char* name, int np_);
		~Contact();
		void read();		
		bool isEmpty()const;
		void display()const;
	};

}

#endif