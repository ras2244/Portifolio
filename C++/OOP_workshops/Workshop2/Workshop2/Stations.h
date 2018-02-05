#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Station.h"

using namespace std;
using namespace w2;
namespace w2{ 

  class Stations{
    int stationCount;
    Station* stationList;
  public:
    ~Stations(){
      delete[] stationList;
    }
    Stations(const char* file);
    void update();
    void restock();
    void report();

  };//class Stations
}