#pragma once
#include <fstream>
#include <iostream>
#include <string>


class Grades{
  double* grade; // to storage students grades
  std::string* stunumb; // to storage studentes number, it could be an int too.
  size_t counter; // Counter how many records to loop into the array.

public:

  Grades() : stunumb(nullptr),grade(0) {}
  Grades(char* f){
    std::fstream in(f, std::ios::in);

    if (in.is_open()){
      std::string line;
      size_t count = 0; // temporarary count
      while(std::getline(in,line)){
        count++;
        in.clear();
        in.seekg(0);
        counter = count; // copy a count into to counter to split the count for the while and for.
        stunumb = new  std::string[counter];
        grade = new double[counter];

        for (int j = 0; j<counter; j++){
          in >> stunumb[j]; //record each student number into stunumb
          in.ignore(1, ' '); // Do not record space
          in >> grade[j]; //record each student number into grades
          in.ignore(1, '\n'); // Do not record jump line, if I record this i do not need to print it ahead.
        }
      }
      
      in.close();

    }
    else{
      throw "cannot open file";
    }
  }
  
  template<typename t>
  void displayGrades(std::ostream& os, t letter) const {
    for (int z = 0; z <counter; z++) {
      os << stunumb[z] << " " << grade[z] << " " << letter(grade[z]) << std::endl; //letter here calls for a especific grade at lambda expression to convert.
    }
  }

  ~Grades(){
    delete[] stunumb;
    delete[] grade;
  }

};