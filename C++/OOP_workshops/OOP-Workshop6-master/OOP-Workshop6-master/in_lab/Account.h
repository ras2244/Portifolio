#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__
#include <iostream>

using std::cout;
using std::ostream;

namespace ict{
   class Account{
      char name_[41];
      double balance_;
   public:
      void display(bool gotoNewline = true)const;      
	    const Account& operator+=(const Account& data);
      Account& operator=(const Account& name);
      friend Account operator+(const Account& b, const Account& c);
      Account();
      Account(double balance);
      Account(const char name[], double balance = 0.0);            
   };
   Account operator+(const Account& b, const Account& c);
   ostream& operator<<(ostream& ref, const Account& s);
};

#endif
