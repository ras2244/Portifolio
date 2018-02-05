#include <cstring>
#include <iostream>
#include <cstring>
#include "String.h"


using namespace std;

namespace ict
{
   // write your implementations here

  void String::deallocate(){
    //delete[] m_data;
    m_data = nullptr;
    m_memSize = 0;
  }

  void String::allocate(int num){
    deallocate();
    m_data = new char[num+1];
    m_memSize = num;
  }

  void String::init(const char* str, unsigned int memSize){
    m_data = nullptr;
    if (memSize >= strlen(str) + 1) {  
      m_memSize = memSize;
    }
    else {
      m_memSize = strlen(str) + 1;
    }
    allocate(m_memSize);
    strcpy(m_data, str);
    m_len = strlen(m_data);
  }

  void String::resize(int newsize){
    char* temp = new char[newsize];
    if (m_data != nullptr) {
      strncpy(temp, m_data, (newsize - 1));
      temp[m_len] = '\0';
    }
    else {
      temp[0] = '\0';
    }
    deallocate();
    m_data = temp;
    m_memSize = newsize;
    
  }

  String::String(){
    m_data = nullptr;
    m_len = 0;
    m_memSize = 0;
  }

  String::String(const char* str, int memsize){
    init(str, memsize);
  }

  String::String(const String& other){
    init(other.m_data, other.m_memSize);
  }

  String& String::operator=(const String& other){
    if (this != &other){
      this->deallocate();
      this->init(other.m_data, other.m_memSize);
    }
    
    return *this;
  }

  String::~String(){
    delete[] m_data;
  }

  int String::getLength()const{
    return m_len;
  }

  int String::getMemSize()const{
    return m_memSize;
  }

  String& String::operator+=(const char* str){
    int count = strlen(str);
    
    if (this->m_len + count + 1 > this->m_memSize) {
      this->resize(m_len + count + 1);
    }

    strcat(m_data, str);
    this->m_len += count;

    return *this;
  }

  String String::operator+(const String& str)const{
    String temp(m_data);
    temp+=str;
    return temp;
  }
  
  String& String::operator+=(String& str){
    return *this+= str.m_data;
    
  }
  
  String& String::operator++(){    
    return *this = String(" ") + *this;
  }

  String String::operator++(int num){
    String temp(*this); 
    *this += " ";
    return temp;
  }

  String::operator const char *()const{
    return m_data;
  }

  String::operator int()const{
    return getLength();
  }

  char& String::operator[](int index){
    if (index > this->m_memSize){
      this->resize(index + ExpansionSize);
    }
    return m_data[index];
  }

  std::istream& String::read(std::istream& is){
    int i = 0;

    for (i = 0; i < m_data[i - 1]; i++){
      if (i>m_memSize){
        this->resize(m_memSize+ ExpansionSize);
      }
      m_data[i] = is.get();
    }
    m_data[i - 1] = '\0';
    return is;
  }

  std::ostream& operator<<(std::ostream& os, const String& c){
    if (c == nullptr){
      os << "";
    }
    else{
      os << (const char*)c;
    }
    return os;
  }

  std::istream& operator>>(std::istream& is, String& c){
    c.read(is);
    return is;
  }

}
  