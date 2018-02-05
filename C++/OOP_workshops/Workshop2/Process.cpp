#include <iostream>
#include "CString.h"
#include "Process.h"

using namespace w1;

void process(char *str){
	w1::CString cs(str);
	cout<<"process(" <<str<<")\n";
}