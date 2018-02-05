#include <fstream>
#include <iostream>
#include <string>
#include "Text.h"

using namespace std;
using namespace w3;

Text::Text(char* f) :count(0){ //constructor needed for w3.cpp:27
  fstream in(f, std::ios::in);

  if (in.is_open()){
    std::string line;
    while (in.eof()==false){
      getline(in, line);
      //cout << "test";
      count++;
      }

      /*std::cout << "file'" << f << "' contains " << count<<" lines\n";*/
      goodTable = new std::string[count];

      /*cout << "good()=" << in.good() << " if set, -none of  the flag is set\n";
      cout << "good()=" << in.fail() << " if set, ios::failbit or ios::badbit is true\n";
      cout << "good()=" << in.eof() << " if set, ios::eofbit is true\n";
      cout << "good()=" << in.bad() << " if set, ios::badbit is true\n";

      std::cout << "clearing all status flags\n";*/
      in.clear();


      /*for (size_t i = 0; i<count; i++){
      getline(in, goodTable[i]);
      }*/
      //goodTable = new std::string[count];

      /*cout << "good()=" << in.good() << " if set, -none of  the flag is set\n";
      cout << "good()=" << in.fail() << " if set, ios::failbit or ios::badbit is true\n";
      cout << "good()=" << in.eof() << " if set, ios::eofbit is true\n";
      cout << "good()=" << in.bad() << " if set, ios::badbit is true\n";*/
      in.seekg(0); // position the file at the beggining (start)


      for (size_t i = 0; i < count; i++){
        getline(in, goodTable[i]);
        auto cr = goodTable[i].find('\r');
        if (cr != std::string::npos){
          goodTable[i].erase(cr);
        }
        in.close();

        //dump();
      }

      /*in.close();*/
      /* size_t num = count;
      if (num>10){
      num = 10;
      }
      for (size_t i = 0; i < count; i++){
      std: cout << " line" << i + 1 << ": '" << goodTable[i] << "'\n";
      }*/
    //}
  }
  else{
    std::cerr << "canot open filer" << f << "'n";
    exit(3);
  }

}

Text& Text::operator = (const Text& rhs){ //constructor needed for w3.cpp:36

  /*std::cout << "copy =op : this/lineTable=" << (void*)this << "/" << (void*)goodTable <<
    " rhs/rhs.lineTable=" << (void*)&rhs << "/" << (void*)rhs.goodTable << "\n";*/
  if (this != &rhs){
    
    delete[] goodTable;
    goodTable = nullptr;
    count = 0;

    count = rhs.count;

    // deep copy
    goodTable = new std::string[count];
    for (size_t i = 0; i < count; i++) {
      goodTable[i] = rhs.goodTable[i];
    }
  }
  return *this;
}

Text&& Text::operator = (Text&& rhs){//constructor needed for w3.cpp:42
  if (this != &rhs){
    delete[] goodTable;
    //move pointer+count (steal brains)
    goodTable = rhs.goodTable;
    count = rhs.count;
    //turn rhs into a zombie
    rhs.count = 0;
    rhs.goodTable = nullptr;
  }
  return std::move(*this);
}

Text::Text(const Text& rhs) :count(0), goodTable(nullptr){ //constructor needed for w3.cpp:48
  *this = rhs;
}

Text::Text(Text&& rhs) :count(0), goodTable(nullptr){ //constructor needed for w3.cpp:54
  *this = std::move(rhs);
}

void Text::dump() {
  size_t number = count;
  if (number > 10) number = 10;
  for (size_t i = 0; i < number; i++) {
    // i+1 to count from 1, not 0
    std::cout << "   line " << i << " -->" << goodTable[i] << "<--\n";
  }
}

size_t Text::size()const{ 
  return count;
}