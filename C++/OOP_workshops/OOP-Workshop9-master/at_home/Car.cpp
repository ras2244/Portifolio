// OOP244 Workshop 9: Inheritance and Virtual Functions
// File	Car.cpp
// Version 1.0
// Date	2016/11/16
// Author Ricardo de oliveira Leal
// Description
// This file have implemented all functions prototyped in 
// Car.h
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// Ricardo		2016/11/16	Workshop 9
///////////////////////////////////////////////////////////

#include "Car.h"

namespace sict
{
  
 /* Car::Car(){
    speed_ = 0;
  }*/

  Car::Car(int max){
    maxSpeed_ = max;
    speed_ = 0;
  }

  void Car::speed(int sp){
    speed_ = sp;
    if (speed_ > maxSpeed_){
      speed_ = maxSpeed_;
    }
    if (speed_ < 0){
      speed_ = 0;
    }
  }

  int Car::maxSpeed()const{
    return maxSpeed_;
  }

  int Car::speed()const{
    return speed_;
  }

  std::ostream& operator << (std::ostream& os,const Car& is){
    is.display(os);
    
    return os;
  }
    
}