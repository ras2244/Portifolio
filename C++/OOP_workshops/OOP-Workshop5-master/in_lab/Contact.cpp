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

  
}