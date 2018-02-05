// OOP244 Workshop 9: Inheritance and Virtual Functions
// File	SportCar.cpp
// Version 1.0
// Date	2016/11/16
// Author Ricardo de oliveira Leal
// Description
// This file have implemented all functions prototypes for 
// SportCar.h
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// Ricardo		2016/11/16	Workshop 9
///////////////////////////////////////////////////////////


#include "SportCar.h"


namespace sict
{
  SportCar::SportCar(){
    noOfPassagers_ = 1;
  }
  /*Car::Car(int max){
    maxSpeed_ = max;
  }*/

  SportCar::SportCar(int maxSp, int numPass) : Car(maxSp){
    noOfPassagers_ = numPass;
  }

  void SportCar::accelerate(){
    int newsp = speed();
    newsp += 40;
    speed(newsp);
  }

  void SportCar::brake(){
    int newsp = speed();
    newsp -= 10;
    speed(newsp);
  }

  std::ostream& SportCar::display(std::ostream& ostr)const {
    if (speed() > 0){
      ostr << "This sport car is carrying " << noOfPassagers_ << " passengers and is traveling at a speed of " << speed() << " km/h.\n";
      return ostr;
    }
    else{
      ostr << "This sport car is carrying " << noOfPassagers_ << " passengers and is parked.\n";
      return ostr;
    }
  }

}