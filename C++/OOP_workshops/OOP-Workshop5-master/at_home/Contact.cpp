// OOP244 Workshop 5: Class with a Resource 
// File	Contact.cpp
// Version 1.1
// Date	2016/10/17
// Author Ricardo de oliveira Leal
// Description
// This file have implemented a new Constructor Copy
// and an assigment operator
///////////////////////////////////////////////////////////
// Name			      Date		      Reason
// Ricardo leal		2016/10/17	  Workshop 5
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"
#include "PhoneNumber.h"

using namespace std;
namespace ict{


	void Contact::read(){
		cout << "Contact Name: ";
		cin.getline(name_, 41, '\n');
		cout << "Please enter " << noPN_ << " phone numbers: " << endl;
		for (int i = 0; i < noPN_; i++){
			cout << i + 1 << ": ";
			phoneNumber_[i].read();
		}
	}

	bool Contact::isEmpty()const{
		return phoneNumber_ == nullptr;
	}

	void Contact::setEmpty(){
		name_[0] = 0;
		noPN_ = 0;
		phoneNumber_ = nullptr;
	}

	Contact::Contact() {
		setEmpty();
	}

	Contact::Contact(const char* name, int pn_) {
		noPN_ = pn_;

		if (strlen(name) > 41) {
			for (int i = 0; i < 41; i++) {
				name_[i] = name[i];
			}
			name_[40] = '\0';
		}
		else {
			strcpy(name_, name);
		}

		phoneNumber_ = new PhoneNumber[pn_];

	}

	void Contact::display()const {
		cout << name_ << endl;
		for (int i = 0; i < noPN_; i++) {
			phoneNumber_[i].display();
		}
		cout << "----------------------------------------" << endl;
	}

	Contact::~Contact() {
		delete[] phoneNumber_;
		phoneNumber_ = nullptr;
	}

	Contact::Contact(const Contact& cp){
    copy(cp);
	}

	Contact& Contact::operator=(const Contact& c){
		if (this == &c){
			delete[] phoneNumber_;
			phoneNumber_ = nullptr;
		}
    copy(c);
		return *this;		
	}

  void Contact::copy(const Contact& cp){
    if (cp.phoneNumber_ != nullptr){
      noPN_ = cp.noPN_;
      strcpy(name_, cp.name_);
      phoneNumber_ = new PhoneNumber[cp.noPN_];
      for (int i = 0; i < cp.noPN_; i++){
        phoneNumber_[i] = cp.phoneNumber_[i];
      }
    }
    else{
      phoneNumber_ = nullptr;
    }
  }

}