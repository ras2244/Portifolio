#ifndef ICT_CUSTOMMADE_H__
#define ICT_CUSTOMMADE_H__
#include "OnShelf.h"
#include "Date.h"
#include "Error.h"
namespace ict {
   class CustomMade : public OnShelf{
   private:
     Date delivery_;
   public:
     CustomMade(const char recTag = 'C') : OnShelf(recTag){};
     void delivery(const Date &value);      
     const Date& delivery()const;
     std::fstream& store(std::fstream& file, bool addNewLine=true)const;
     std::fstream& load(std::fstream& file);
     std::ostream& display(std::ostream& os, bool linear)const;
     std::istream& conInput(std::istream& istr);

   };
}


#endif
