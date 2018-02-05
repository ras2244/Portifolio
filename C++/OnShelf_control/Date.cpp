// header files go here
#include <iostream>
#include "Date.h"
#include "wpgeneral.h"
using namespace std;
namespace ict {
   // returns a unique value representing the date
   // this value is used to compare two dates
   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }

   // bool validate(), this is an optional private function
   // for validation logic and setting the _readErrorCode.
   // see the read() function description for more details
   



   // mdays():
   // returns the day of the month.
   // _mon value must be set for this function to work
   // if _mon is invalid, this function returns -1
   // leap years are considered in this logic
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

   // constructors

   Date::Date() {
	   year_ = 0;
   }

   Date::Date(int year, int mon, int day) {
     year_ = year;
     mon_ = mon;
     day_ = day;
     readErrorCode_ = NO_ERROR;		
   }


   // member functions
   
   void Date::errCode(int errorCode) {
     readErrorCode_ = errorCode;   
   }

   int Date::errCode()const {
     int result = 0;
	   result=readErrorCode_;    
     return result;
   }

   bool Date::bad() const {
    
     bool result = errCode() != 0 ? true : false;
     return result;
   }

   // operators
   bool Date::operator==(const Date& D)const {
	   bool result = false;
	   if (this->value()==D.value()) {
		   result = true;
	   }
	   else {
		   result = false;
	   }
	   return result;

   }

   bool Date::operator<(const Date& D)const {
	   bool result = false;
	   if (this->value() < D.value()) {
		   result = true;
	   }
	   else {
		   result = false;
	   }
	   return result;  
   }

   bool Date::operator!=(const Date& D)const {
	   bool result = false;
	   if (this->value()!= D.value()) {
		   result = true;
	   }
	   else {
		   result = false;
	   }
	   return result;
   }

   bool Date::operator>(const Date& D)const {
	   bool result = false;
	   if (this->value()> D.value()) {
		   result = true;
	   }
	   else {
		   result = false;
	   }
	   return result;
   }

   bool Date::operator<=(const Date& D)const {
	   bool result = false;
	   if (this->value()<= D.value()) {
		   result = true;
	   }
	   else {
		   result = false;
	   }
	   return result;
   }

   bool Date::operator>=(const Date& D)const {
	   bool result = false;
	   if (this->value()>=D.value()) {
		   result = true;
	   }
	   else {
		   result = false;
	   }
	   return result;
   }
   
   // IO functions

  istream& Date::read(std::istream& istr){

	 char t;

	 /*istr.clear();
   istr.ignore();*/
	 //istr.ignore(0, '\n');
	 istr >> year_ >> t >> mon_ >> t >> day_;
  
	 /*istr >> year_;
	 t=istr.get();
	 istr >> mon_;
	 istr.get();
	 istr>> day_;     */
    
   if(t!='/'){
     readErrorCode_ = CIN_FAILED;
     return istr;
	 }
    
   if (year_>MAX_YEAR || year_<MIN_YEAR) {
     readErrorCode_ = YEAR_ERROR;
     return istr;
   }
   if (mon_ < 1 || mon_>12) {
     readErrorCode_ = MON_ERROR;
     return istr;
   }

   if (day_<1||day_>31) {
     readErrorCode_ = DAY_ERROR;
     return istr;
   }
    

    if (mdays()==-1) {
         readErrorCode_ = DAY_ERROR;
         return istr;
       }
       
    readErrorCode_ = NO_ERROR;          
	  return istr;

   }

   ostream& Date::write(std::ostream& ostr)const {
	   ostr << year_<<"/";
		 if (mon_ < 10) {
			 ostr << "0";
		 }
		 ostr << mon_ << "/";
     if (day_ < 10) {
       ostr << "0";
     }
     ostr << day_;
       
     return ostr;
   }

   // non-memeber operator overloads
   istream& operator >> (std::istream& in, Date& s) {
     s.read(in);
     return in;

   }

   ostream& operator<<(std::ostream& os, const Date& s) {
     s.write(os);
     return os;
   }
}
