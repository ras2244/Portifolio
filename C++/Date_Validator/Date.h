#ifndef ICT_DATE_H__
#define ICT_DATE_H__
#define NO_ERROR   0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR  3
#define DAY_ERROR  4
#include <iostream>
#include "wpgeneral.h"

using namespace std;
namespace ict {
  // Error code values go here
	

   class Date {
   private:
      // private member variables
	   int year_;
	   int mon_;
	   int day_;
	   int readErrorCode_;
      // private member functions and setters
     void errCode(int eCode);
     int value()const;     
   public:
      // constructors
	   Date();
     Date(int year, int mon, int day);
      // operator overloads
     bool operator==(const Date& D)const;
     bool operator!=(const Date& D)const;
     bool operator<(const Date& D)const;
     bool operator>(const Date& D)const;
     bool operator<=(const Date& D)const;
     bool operator>=(const Date& D)const;
      // IO member functions
     istream& read(std::istream& istr);
     ostream& write(std::ostream& ostr) const;     
      // public member functions and getters
      int mdays()const;
      int errCode()const;
      bool bad() const;
   };
   // operator << and >> overloads prototypes for ostream and istream go here
   istream& operator>>(std::istream& in, Date& s);
   ostream& operator<<(std::ostream& os, const Date& s);
   
}
#endif
