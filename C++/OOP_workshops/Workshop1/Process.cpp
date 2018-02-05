#include <iostream>
#include "CString.h"
#include "Process.h"

//using namespace w1;
//using namespace std;

void process(char *str){
	w1::CString cs(str);
	std::cout << cs << "\n";
}