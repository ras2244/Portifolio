#pragma once

#include <string>
#include <array>
#include <iostream>
#include <vector>

namespace cicle {

	class Cicle {

		
		unsigned int index;
		Cicle* a;
		unsigned int k;

		Cicle() {
			a = new int*[index];
		}

		Cicle& operator=(const Cicle& rhs) {

		}

	};

}