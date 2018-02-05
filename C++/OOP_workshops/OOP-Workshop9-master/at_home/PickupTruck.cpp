// OOP244 Workshop 9: Inheritance and Virtual Functions
// File	PickupTruck.cpp
// Version 1.0
// Date	2016/11/16
// Author Ricardo de oliveira Leal
// Description
// This file have implemented all functions prototyped in 
// PickupTruck.h
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// Ricardo		2016/11/16	Workshop 9
///////////////////////////////////////////////////////////

#include "PickupTruck.h"
#include <cstring>

namespace sict
{
  PickupTruck::PickupTruck(){
    loadAmount_ = 0;
    loadedMaterial[0] = 0;
  }

  void PickupTruck::load(const char* str, int numb){
    loadAmount_ = numb;
    strncpy(loadedMaterial, str, 31);
  }

  void PickupTruck::unload(){
    loadAmount_ = 0;
  }

  bool PickupTruck::isEmpty()const{
    if (loadAmount_ == 0){
      return true;
    }

    return false;
  }

  void PickupTruck ::accelerate(){
    int newsp = speed();
    newsp += 20;
    speed(newsp);
  }

  void PickupTruck::brake(){
    int newsp = speed();
    newsp -= 5;
    speed(newsp);
  }

  std::ostream& PickupTruck::display(std::ostream& ostr)const{
    if (isEmpty() == true){
      ostr << "This pickup truck is not carrying any load";
      
    }
    else{
      ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial;
    }

    if (speed() > 0){
      ostr << ", traveling at the speed of " << speed() << " km/h.\n";
    }
    else{
      ostr << " and is parked.\n";
    }
    
    return ostr;

  }
}