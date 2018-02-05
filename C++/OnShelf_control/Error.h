#ifndef SICT_ERROR_H__
#define SICT_ERROR_H__
#include <iostream>

using namespace std;
namespace ict{
  class Error{
    char* message_;
  public:
    Error();
    Error(const char* Error);
    Error(const Error& em) = delete;
    Error& operator=(const Error& em) = delete;
    Error& operator=(const char* errorMassage);
    virtual ~Error();
    void clear();
    bool isClear()const;
    void message(const char* value);
    const char* message()const;
  };
  ostream& operator<<(ostream& os, const Error& str);
  // operator<< overload prototype
}
#endif

