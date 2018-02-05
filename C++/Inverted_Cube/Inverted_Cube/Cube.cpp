#include <iostream>
#include "Cube.h"

using namespace std;

namespace Inv_cube {

	
	void Cube::printArray() {
		
			cout << " The initial Array is: {";
			for (int j = 0; j < SIZE; j++) {
				cout << initial_Array1[j];
				if (j < 3) {
					cout << ",";
				}
			}
			cout << "} ";				
			
			cout << "{";
			for (int j = 0; j < SIZE; j++) {
				cout << initial_Array2[j];
				if (j < 3) {
					cout << ",";
				}
			}
			cout << "} ";		
			
			cout << "{";
			for (int j = 0; j < SIZE; j++) {
				cout << initial_Array3[j];
				if (j < 3) {
					cout << ",";
				}
			}
			cout << "} ";			
			
			cout << "{";
			for (int j = 0; j < SIZE; j++) {
				cout << initial_Array4[j];
				if (j < 3) {
					cout << ",";
				}
			}
			cout << "} \n";	
			
	}

	void Cube::rotateArray() {
		int last = 15;
		for (int i = 0; i < SIZE; i++) {
			Inv_Array1[i] = DefaultArray[last-3];
			last=last - SIZE;
		}
		last = 15;
		for (int i = 0; i < 4; i++) {
			Inv_Array2[i] = DefaultArray[last - 2];
			last = last - SIZE;
		}
		last = 15;
		for (int i = 0; i < SIZE; i++) {
			Inv_Array3[i] = DefaultArray[last - 1];
			last = last - SIZE;
		}
		last = 15;
		for (int i = 0; i < SIZE; i++) {
			Inv_Array4[i] = DefaultArray[last];
			last = last - SIZE;
		}

		cout << " The rotate Array is: {"; 
		for (int j = 0; j < SIZE; j++) {
			cout << Inv_Array1[j];
			if (j < 3) {
				cout << ",";
			}
		}
		cout << "} ";

		cout << "{";
		for (int j = 0; j < SIZE; j++) {
			cout << Inv_Array2[j];
			if (j < 3) {
				cout << ",";
			}
		}
		cout << "} ";


		cout << "{";
		for (int j = 0; j < SIZE; j++) {
			cout << Inv_Array3[j];
			if (j < 3) {
				cout << ",";
			}
		}
		cout << "} ";

		cout << "{";
		for (int j = 0; j < SIZE; j++) {
			cout << Inv_Array4[j];
			if (j < 3) {
				cout << ",";
			}
		}
		cout << "} \n";
	}

	Cube::~Cube() {
	
	}

}