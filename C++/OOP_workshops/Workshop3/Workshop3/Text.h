#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace w3{
  

  class Text{
    size_t count;
    string* goodTable;
  public:
    ~Text(){
      delete[] goodTable;
      goodTable = nullptr;
    }

    Text():count(0), goodTable(nullptr){}// default constructor needed for w3.cpp:21

    Text(char* f);
    Text& operator = (const Text& rhs); //copy assigment

    Text&& operator = (Text&& rhs); //move assigment

    Text(const Text& rhs); //copy constructor

    Text(Text&& rhs); //move constructor

    void dump();

    size_t size()const;

  };//text
} // namespace