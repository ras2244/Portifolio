#ifndef ICT_SUPERHERO_H__
#define ICT_SUPERHERO_H__
#include "Hero.h"
class SuperHero : public Hero  {
  protected:
   double multStrg_;
public:
   SuperHero(){ strength_ = -1.0; }
   SuperHero(const char* str, const double num1, const double num2);
   double getStrength()const;
   void display(std::ostream&)const;
   void operator *=(SuperHero&);
};

#endif

