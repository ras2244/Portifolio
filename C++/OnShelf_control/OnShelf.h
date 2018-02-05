#ifndef ICT_ONSHELF_H__
#define ICT_ONSHELF_H__
#include "Good.h"
#include "Error.h"
#include "ReadWritable.h"
#include <fstream>
namespace ict {
   class OnShelf : public Good{
   private:
     char recTag_;
   protected:
     Error err_;
   public:
     OnShelf(const char filetag = 'O');
     std::fstream& store(std::fstream& file, bool addNewLine=true)const;
     std::fstream& load(std::fstream& file);
     std::ostream& display(std::ostream& os, bool linear)const;
     std::istream& conInput(std::istream& istr);
   };
}
#endif