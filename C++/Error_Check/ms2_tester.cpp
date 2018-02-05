
// File	ms2_tester.cpp
// Version 1.0
// Date	2016/10/28
// Author	Ricardo Leal
// Description
// This program test the student implementation of the Error class
// for submission.
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Error.h"
using namespace std;
using namespace ict;
int main(){
  Error T("Testing Error Message");
  Error e;
  cout << T << endl << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "failed!") << endl;
  for (int i = 0; i < 1000000; i++){
    e = "Some error message that is really long long  long  long  long  long  long  long"
        " long  long  long  long  long  long  long  long  long  long  long  long  long";
  }
  cout << e << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
  e.message("Short Message");
  cout << e << endl << e.message() << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
  e.clear();
  cout << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
  return 0;
}