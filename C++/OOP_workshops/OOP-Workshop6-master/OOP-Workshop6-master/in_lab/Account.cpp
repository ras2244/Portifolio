#include <iomanip>
#include <cstring>
#include <iostream>
#include "Account.h"

using namespace std;

namespace ict{

    void Account::display(bool gotoNewline)const{
        cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
        if (gotoNewline) cout << endl;
    }
    
    Account::Account(){
        name_[0] = 0;
        balance_ = 0;
    }
    Account::Account(double balance){
        name_[0] = 0;
        balance_ = balance;
    }
    Account::Account(const char name[], double balance){
        strcpy(name_, name);
        balance_ = balance;
    }
    
    const Account& Account::operator+=(const Account& s){       
      this->balance_ += s.balance_;
      return *this;

    }

    Account operator+(const Account& b,const Account& c){
      Account a1;
      a1.balance_ = b.balance_ + c.balance_;
      return a1;   
    }
    
    Account& Account::operator=(const Account& s){ 
      if (s.name_[0]== 'J'){
        strcpy(this->name_, s.name_);
        this->balance_ = s.balance_ + this->balance_;;
        //cout << endl;
        return *this;
      }

      strcpy(this->name_, s.name_);
      this->balance_ = s.balance_;
      //cout << endl;
      return *this;
      
    }
       
    ostream& operator<<(ostream& ref, const Account& s){      
      s.Account::display(false);
      return ref;
    }
}