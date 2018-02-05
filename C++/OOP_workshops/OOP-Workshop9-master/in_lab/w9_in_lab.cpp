#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"

using namespace std;
using namespace sict;

// your Drive(...) function goes here
void Drive(Car& move){
  move.accelerate();
  move.brake();
  move.display(cout)<<endl;
}


// your Stop(...) function goes here

void Stop(Car& move){
  while (move.speed() != 0){
    move.brake();
  }
  move.display(cout)<<endl;
}


int main()
{
	SportCar Tesla(240, 2);
	PickupTruck Ford;
	Tesla.display(cout) << endl;
	Ford.display(cout) << endl;

	Ford.load("Bricks", 3500);
	Drive(Tesla);
	Drive(Ford);
	Stop(Tesla);
	Stop(Ford);
	Ford.unload();

	Tesla.display(cout) << endl;
	Ford.display(cout) << endl;

	return 0;
}
/*
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
This sport car is carrying 2 passengers and is traveling at a speed of 30 km/h.
This pickup truck is carrying 3500 kgs of Bricks, traveling at the speed of 15 km/h.
This sport car is carrying 2 passengers and is parked.
This pickup truck is carrying 3500 kgs of Bricks and is parked.
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
*/