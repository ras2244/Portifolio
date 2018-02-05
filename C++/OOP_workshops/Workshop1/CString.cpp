#include <iostream>
#include <cstring>
#include "CString.h"

//using namespace std;
//using namespace w1;

namespace w1{

	CString::CString(const char* s){
		strncpy(this->str,s,num);
		this->str[num]='\0';
	}
	void CString::display(std::ostream & os){
		os<<str;
	}	

	std::ostream& operator<<(std::ostream& os, CString& cs){
		static int calls =0;
		cout<<calls<<": ";
		cs.display(os);
		calls++;
		return os;
	}
}//namespace