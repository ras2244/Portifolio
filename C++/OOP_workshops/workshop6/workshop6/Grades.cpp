//#include <fstream>
//#include <iostream>
//#include <string>
//#include "Grades.h"
//
//using namespace std;
//
//
//
//Grades::Grades(char* f){
//  std::fstream in(f, std::ios::in);
//
//  if (in.is_open()){
//    std::string line;
//    for (i = 0; getline(in, line); i++){
//      in.clear();
//      in.seekg(0, std::ios::beg);
//      stunumb = new  std::string[i];
//      grade = new double[i];
//
//      for (i = 0; in.good(); i++){
//        in >> stunumb[i];
//        in.ignore(1, ' ');
//        in>>grade[i];
//        in.ignore(1, '\n');
//      }
//    }
//
//    in.close();
//  
//  }
//  else{
//    throw "cannot open file";    
//  }
//
//  
//
//
//}