//Inverted_Cube.cpp : Defines the entry point for the console application.
//In a cube 4x4 where block 1 is{1234} 2 is {5678} 3 is {9101112} and 4 is {13141516}
//The rotation will produce a new arrangement and 


#include "cube.h"


int main()
{
    
	Inv_cube::Cube start;

	start.printArray();
	start.rotateArray();
	return 0;
}

