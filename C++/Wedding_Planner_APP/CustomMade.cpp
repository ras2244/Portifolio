#include "CustomMade.h"
#include "OnShelf.h"
#include "error.h"
#include "Good.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
namespace ict {

  void CustomMade::delivery(const Date &value){
    delivery_ = value;
  }

  const Date& CustomMade::delivery()const{
    return delivery_;
  }

  std::fstream& CustomMade::store(std::fstream& file, bool addNewLine)const{
	  if (!addNewLine){ 

      OnShelf::store(file, true);
      file << left << "," << delivery() << endl;
    }

		else{
         
			OnShelf::store(file, false);
      file << left << "," << delivery();
      file << endl;
		}

		return file;
	
  }
  std::fstream& CustomMade::load(std::fstream& file){
		
    OnShelf::load(file);
    file.ignore();
    delivery_.read(file);       
		return file;
  }
  std::ostream& CustomMade::display(std::ostream& os, bool linear)const{
		OnShelf::display(os, linear);
				
		if (err_.isClear()){
			if (linear == true){

        os<<left << delivery();
			}
			else{
				os << endl<<"delivery date: " << delivery();
			}
			return os;
		}
		else{
			return os;
		}		
  }
	std::istream& CustomMade::conInput(std::istream& istr){
    err_.clear();
    OnShelf::conInput(istr);
		Date date;
		if (err_.isClear()){      
			cout << "delivery date (YYYY/MM/DD) : ";
			istr >> date;
      /*istr.ignore();
      date.read(istr);*/
		if (date.bad()){      
      if (date.errCode() == 1){
					err_.message("Invalid Date Entry");
				}
      else if (date.errCode() == 2){
					err_.message("Invalid Year in Date Entry");
				}
      else if (date.errCode() == 3){
					err_.message("Invalid Month in Date Entry");
				}
      else if (date.errCode() == 4){
					err_.message("Invalid Day in Date Entry");
				}

      istr.setstate(std::ios::failbit);
			}
      else{          
        delivery(date);
        err_.clear();
        
      }
		}
		return istr;
	}	
}
