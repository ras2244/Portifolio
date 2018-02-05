#include "SuperHero.h"
#include <cstring>

SuperHero::SuperHero(const char* str, const double num1, const double num2) {
  for (int i = 0; i < 21; i++) {
    name_[i] = str[i];
  }
  strength_ = num1;
  multStrg_ = num2;
}

double SuperHero::getStrength() const {
   return strength_;
}

void SuperHero::operator *=(SuperHero& newOne) {
  if (newOne.getStrength() < getStrength()) {
    strength_ += newOne.getStrength();   
    newOne.strength_ = -1.0;
  }
  else {
    newOne.strength_ += strength_;
    strcpy(name_, newOne.name_);
    Hero();
  }
}

  void SuperHero::display(std::ostream&os)const {
    if (!(Hero::isEmpty())) {

      os << "living superhero! ";
      Hero::display(os);
    }
    else
      os <<name_<< " deceased superhero!" << std::endl;
      
}

