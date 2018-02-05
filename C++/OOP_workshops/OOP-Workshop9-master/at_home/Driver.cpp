#include "Driver.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sict
{


  Driver::Driver(const char* name, Car& theCar) : car_(theCar){
    strncpy(name_, name, 31);
  }

  void Driver::drive(){
    car_.accelerate();
    car_.brake();
    showStatus();
  }
  
  void Driver::stop(){
    while (car_.speed() !=0){
      car_.brake();
    }
    /*showStatus();*/
    cout << name_ << " is driving this car.\n";
    /*cout << endl;*/
    cout << car_;
  }

  void Driver::showStatus(){
    cout << name_ << " is driving this car.\n";
    /*cout << endl;*/
    cout << car_;
  }

}
