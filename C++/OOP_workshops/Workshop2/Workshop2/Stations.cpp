#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Stations.h"

using namespace std;
using namespace w2;

namespace w2{

  Stations::Stations(const char* file) : stationCount(0),stationList(nullptr){
    //std::cout << "file=" << file << "\n";
    fstream is(file, ios::in);
    if (!is.is_open()){
      std::cerr << "Cannot open file '" << file << "'\n";
      exit(2);
    }
    string s;
    std::getline(is, s);
    //std::cout << "s='" << s << "'\n";
    int index = 0;
    while (index < s.size()){
      if (isdigit(s[index])){
        stationCount = 10 * stationCount + (s[index] - '0');
        index++;
      }
      else{
        break;
      }
    }
    if (index < s.size() && s[index] != ';'){
      cout << "First record of '" << file << "' was not terminated with a ';'\n";
      exit(3);
    }


    stationList = new Station[stationCount];
    for (int count = 0; count < stationCount; count++){
      stationList[count] = Station(is);
    }

    is.close();
  }

  void Stations::update(){
    cout << "\nPasses Sold :" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < stationCount; i++){
      int student, adult;
      cout << stationList[i].getName() << "\n";
      cout << " Student Passes sold : ";
      cin >> student;
      cout << " Adult   Passes sold : ";
      cin >> adult;
      stationList[i].update(PASS_STUDENT, -student);
      stationList[i].update(PASS_ADULT, -adult);
    }
  }

  void Stations::restock(){
    cout << "\nPasses Added :" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < stationCount; i++){
      int student, adult;
      cout << stationList[i].getName() << "\n";
      cout << " Student Passes added : ";
      cin >> student;
      cout << " Adult   Passes added : ";
      cin >> adult;
      stationList[i].update(PASS_STUDENT, +student);
      stationList[i].update(PASS_ADULT, +adult);
    }
  }

  void Stations::report(){
    cout << "\nPasses In Stock : Student Adult" << endl;
    cout << "-------------------------------" << endl;

    for (int s = 0; s < stationCount; s++){
      stationList[s].report();
    }
  }

}//namespace