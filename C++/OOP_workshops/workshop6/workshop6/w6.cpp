#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << argv[0] <<
      ": incorrect number of arguments\n";
    std::cerr << "Usage: " << argv[0] << " file_name\n";
    return 1;
  }


  Grades grades(argv[1]);
  // define the lambda expression for letter 
  auto letter = [](double grade)->std::string{ //creates a variable letter with lambda expression, where a double grades will point to a string.
    std::string letterGrade; //declare a string to receive a char for each grade.
    if (grade >= 90)
      letterGrade = "A+";
    else if (grade>80)
      letterGrade = "A";
    else if (grade>75)
      letterGrade = "B+";
    else if (grade>70)
      letterGrade = "B";
    else if (grade>65)
      letterGrade = "C+";
    else if (grade>60)
      letterGrade = "C";
    else if (grade>55)
      letterGrade = "D+";
    else if (grade>50)
      letterGrade = "D";
    else
      letterGrade = "F";

    return letterGrade;
  };


  grades.displayGrades(std::cout, letter); 
  // call grades. display passing letter variable wich enclose the lambda expression.
  //letter is the Lambda expression

  std::cout << "Press any key to continue ... ";
  std::cin.get();
}