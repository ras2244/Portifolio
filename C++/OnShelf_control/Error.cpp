#include "Error.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace ict{

  Error::Error(){
    message_ = nullptr;
  }

  Error::Error(const char* Error){
    message_ = nullptr;
    message(Error);
  }

  void Error::message(const char* value){
    delete[] message_;
    message_ = new char[strlen(value) + 1];
    strcpy(message_, value);
  }

  const char* Error::message()const{
    return message_;
  }

  Error::~Error(){
    delete[] message_;    
  }

  void Error::clear(){
    delete[] message_;
    message_ = nullptr;
  }

  bool Error::isClear()const{
    if (message_ == nullptr){
      return true;
    }
    else{
      return false;
    }   
  }


  Error& Error::operator=(const char* errorMessage){
    clear();
    message(errorMessage);
    return *this;    
  }

  std::ostream& operator<<(std::ostream& os, const Error& str){

    if (str.isClear() == false){
      os << str.message();
      return os;
    }

    else{
      return os;
    }
  }
}



