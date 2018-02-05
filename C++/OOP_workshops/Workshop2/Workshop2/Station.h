#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT };
namespace w2{
  
  class Station{   
    string stationName;
    unsigned int passes[PASS_COUNT];
  public:
    Station(){};
    Station(std::istream& is); 

    void set(const string& n, unsigned s, unsigned a);

    void update(PassType pt, int num);

    unsigned inStock(PassType pt) const;

    const std::string& getName() const;

    void report();
  };
}//namespace