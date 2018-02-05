#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Station.h"

using namespace std;
//using namespace w2;

namespace w2{

    Station::Station(istream& is){
    string s;
    std::getline(is,s);
    //std::cout << "station: s='" << s << "'\n";
    //string name;
    size_t index = 0;
    while (index < s.size()){
      
      //cout << "Station: stationName='" << stationName << "'\n";

      //if (index < s.size() && s[index] != ';'){
      if (s[index] != ';'){
        stationName += s[index];
        index++;
      }
      else{
        break;
      }
      
    }

    if (s[index] != ';'){      
      std::cerr << "station record name for" << stationName << "'was not terminated with a ';' \n";
      exit(3);
    }
    index++;
    int student = 0;
    while (index < s.size()){
      if (isdigit(s[index])){
        student = 10 * student + (s[index] - '0');
        index++;
      }
      else{
        break;
      }
    }
    //cout << "station: student = " << student << "\n";
    if (!(index < s.size() || s[index] == ' ')){
      std::cerr << "student pass count for '" << stationName << "' was not terminated with a ' '\n";
      exit(4);
    }

    index++; //skip ' '
    int adult = 0;
    while (index < s.size()){
      if (isdigit(s[index])) {
        adult = 10 * adult + (s[index] - '0');
        //convert character to number
        index++;
      }
      else{
        break;
      }
    }
    //std::cout << "station: adult = " << adult << "\n";
    set(stationName, student, adult);
    //stationName
  }

    void Station::set(const string& n, unsigned s, unsigned a){
      //sets the instance variables to the values received in its parameter
      stationName = n;
      passes[PASS_STUDENT] = s;
      passes[PASS_ADULT] = a;
    }

    void Station::update(PassType pt, int num){
      //updates the number of passes - sold if negative, added if positive
      passes[pt] += num;
    }

    unsigned Station::inStock(PassType pt) const{
      //returns the number of passes of the requested type
      return passes[pt];
    }

    const std::string& Station::getName() const{
      //returns a reference to a string object holding the name of the station
      return stationName;
    }

    void Station::report(){
      std::cout << left << setw(22)<< stationName
        <<setw(6)<< passes[PASS_STUDENT]
        <<setw(6)<< passes[PASS_ADULT] << "\n";
    }

}//namespace