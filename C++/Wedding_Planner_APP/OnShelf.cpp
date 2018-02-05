#include "OnShelf.h"
#include "error.h"
#include <cstring>
#include <iostream>
#include <iomanip>


using namespace std;

namespace ict {

  OnShelf::OnShelf(const char filetag){
      recTag_ = filetag;
   
  }

  std::fstream& OnShelf::store(std::fstream& file, bool addNewLine)const{
	  if (addNewLine){
		  file << recTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() <<","<< quantity() << "," << qtyNeeded() << endl;
	  }
	  else{
      file << recTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << qtyNeeded();
	  }
	  return file;
  }

  std::fstream& OnShelf::load(std::fstream& file){
    char tname[31];
	  char tsku[MAX_SKU_LEN + 1];
	  int tqtyneed, tqty;	  
	  double tprice;
    bool ttax;      
       
    file.getline(tsku,MAX_SKU_LEN+1,',');
    sku(tsku);
    file.getline(tname, 21, ',');
    name(tname);
    
    file >> tprice;
    price(tprice);
   
    file.ignore();
	  file >> ttax;
    taxed(ttax);
	  
    file.ignore();
	  file >> tqty;	  
    quantity(tqty);

    file.ignore();
	  file >> tqtyneed;
    qtyNeeded(tqtyneed);

	  
	  return file;

  }

  std::ostream& OnShelf::display(std::ostream& os, bool linear)const{  
	  
	  if (!err_.isClear()){
		  os << err_ << endl;
	  }
	  else{
		  if (linear == true){       
        if (taxed()==true){          
          os << setw(MAX_SKU_LEN) << sku() << "|" << left
            << setw(20) << name() << "|" << right << setprecision(2)<<fixed
            << setw(7) << cost() << "|" <<" t "<<"|"<< right << setw(4) << quantity()
            <<"|"<< right << setw(4) << qtyNeeded()<<"|";
        }
        else{
          os << setw(MAX_SKU_LEN) << sku() << "|" << left
            << setw(20) << name() << "|" << right << setprecision(2)<<fixed
            << setw(7) << cost() << "|" << "   " << "|" << right << setw(4) << quantity()
            << "|" << right << setw(4) << qtyNeeded() << "|";
        }
		  }
		  else{        
			  if (taxed()==true){          
				  os << "Sku: " << sku() << endl;
				  os << "Name: " << name() << endl;
				  os << "Price: " << setprecision(2) <<fixed<<price() << endl;
				  os << "Price after tax: " << setprecision(2) <<fixed << cost() << endl;
				  os << "Quantity On Hand: " << quantity() << endl;
          os << "Quantity Needed: " << qtyNeeded();
			  }
			  else{
				  os << "Sku: " << sku() << endl;
				  os << "Name: " << name() << endl;
				  os << "Price: " << setprecision(2) << price() << endl;
				  os << "Price after tax: N/A"<< endl;
				  os << "Quantity On Hand: " << quantity() << endl;
          os << "Quantity Needed: " << qtyNeeded();
			  }
		  }
	  }

	  return os;
  }

  std::istream& OnShelf::conInput(std::istream& istr){
    char tname[31];
    char tsku[MAX_SKU_LEN + 1];
    int tqtyneed, tqty;   
    double tprice;
    char tax;

    if (!istr.fail()){
      err_.clear();
      cout << "Sku: ";
      istr >> tsku;
      sku(tsku);
      istr.clear();
      cout << "Name: ";
      istr >> tname;
      name(tname);
      istr.clear();
      if (err_.isClear()){
        cout << "Price: ";
        istr >> tprice;

        if (!istr.fail()){
          price(tprice);
          istr.clear();
        }
        else{
          err_.message("Invalid Price Entry");
         // istr.setstate(ios::failbit);

        }
      }
      if (err_.isClear()){
        cout << "Taxed: ";
        istr >> tax;

        if (!istr.fail()){
          if (tax == 'Y' || tax == 'y'){
            taxed(true);
            //cost();
            istr.clear();
          }
          else if (tax == 'N' || tax == 'n'){
            taxed(false);
            istr.clear();
          }
          else{
            err_.message("Only (Y)es or (N)o are acceptable");
            istr.setstate(ios::failbit);
          }          
        }
        else{
          err_.message("Only (Y)es or (N)o are acceptable");
          istr.setstate(ios::failbit);
        }
      }

      if (err_.isClear()){
        cout << "Quantity On hand: ";
        istr >> tqty;
        if (!istr.fail()){
          quantity(tqty);
          istr.clear();
        }
        else{
          err_.message("Invalid Quantity Entry");
          istr.setstate(ios::failbit);
        }
      }

      if (err_.isClear()){
        cout << "Quantity Needed: ";
        istr >> tqtyneed;
        if (!istr.fail()){
          qtyNeeded(tqtyneed);
          istr.clear();
        }
        else{
          err_.message("Invalid Quantity Needed Entry");
          istr.setstate(ios::failbit);
        }      
      }

  }
		return istr;
  }
}
