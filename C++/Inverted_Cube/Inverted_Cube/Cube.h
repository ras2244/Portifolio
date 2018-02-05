#pragma once
#include <string>
#include <array>


#define SIZE 4


namespace Inv_cube {
	class Cube {
		int DefaultArray[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		int initial_Array1 [4], initial_Array2[4], initial_Array3[4], initial_Array4[4];
		
		int Inv_Array1 [4],Inv_Array2 [4], Inv_Array3[4], Inv_Array4[4];
		
	public:
		Cube() {
			int i=0;
			//int next;
			while (i < 16) {
				for (int j = 0; j < SIZE; j++) {
					initial_Array1[j] = DefaultArray[i];
					i++;
				}
				
				for (int j = 0; j < SIZE; j++) {
					initial_Array2[j] = DefaultArray[i];
					i++;
				}
				
				for (int j = 0; j < SIZE; j++) {
					initial_Array3[j] = DefaultArray[i];
					i++;
				}
				
				for (int j = 0; j < 4; j++) {
					initial_Array4[j] = DefaultArray[i];
					i++;
				}
				i = 16;
			}
			for (int i = 0; i < 4; i++) {			
				Inv_Array1[i] = 0;
				Inv_Array2[i] = 0;
				Inv_Array3[i] = 0;
				Inv_Array4[i] = 0;
			}

		}

		
		void printArray();
		void rotateArray();


		
		~Cube();



	};
}