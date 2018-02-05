#pragma once
#include <iostream>

using namespace std;
int const num=3;

namespace w1{
	class CString{
		char str[num+1];
		public:
		CString(const char* s);
		void display(ostream & os);
	};
	ostream& operator<<(ostream& os, CString& cs);
}//namespace