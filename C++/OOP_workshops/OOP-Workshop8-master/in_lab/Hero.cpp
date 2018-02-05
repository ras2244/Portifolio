#include "Hero.h"
#include <iostream>



bool Hero::isEmpty() const {
	if (strength_ == 0) {
		return true;
	}
	else {
		return false;
	}
}

double Hero::getStrength() const {
	if (isEmpty() != true) {
		return strength_;
	}
	else {
		//Hero();
		return strength_;
	}
}

void Hero::display(std::ostream& os)const {
	os << name_ << "-" << strength_ << "\n";
}

void Hero::operator-=(double strength) {
	if (strength < strength_) {
		strength_ -= strength;
	}
	else {
		strength_ = 0.0;
	}
}

void Hero::operator+=(double strength) {
	strength_ += strength;
}

bool operator<(const Hero& right, const Hero& left) {
	if (right.getStrength() < left.getStrength()) {
		return true;
	}
	else {
		return false;
	}

}

Hero::Hero() {
	strength_ = 0.0;
}

Hero::Hero(const char* str, const double num) {
	for (int i = 0 ; i < 21; i++) {
		name_[i] = str[i];
	}
	strength_ = num;
}