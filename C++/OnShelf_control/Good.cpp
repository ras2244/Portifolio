#include <cstring>
#include <iostream>
#include "wpgeneral.h"
#include "Good.h"
using namespace std;
namespace ict {

  Good::~Good() {
    delete[] name_;
  }

  Good::Good() {
		quantity_ = 0;
    qtyNeeded_ = 0;
    name_ = nullptr;
    sku_[0] = '\0';
  }

  Good::Good(const char* sku, const char* name, double price, int qty, bool tax) {
    strncpy(sku_, sku, MAX_SKU_LEN+1);
    name_ = new char[strlen(name) + 1];
    quantity_ = 0;
    qtyNeeded_ = qty;
    taxed_ = tax;
  }

  Good::Good(const Good& cp) {
 
    strncpy(sku_, cp.sku_, MAX_SKU_LEN + 1);
    price_ = cp.price_;
    taxed_ = cp.taxed_;
    quantity_ = cp.quantity_;
    qtyNeeded_ = cp.qtyNeeded_;
    if (cp.name_ != nullptr) {
     /*delete[] name_;*/
      name_ = new char[strlen(cp.name_) + 1];
      strcpy(name_, cp.name_);
    }
    else {
      name_ = nullptr;
    }
  }


  Good& Good::operator=(const Good& cp) {
    if (this != &cp) {
      delete[] name_;
      strncpy(sku_, cp.sku_, MAX_SKU_LEN + 1);
      price_ = cp.price_;
      taxed_ = cp.taxed_;
      quantity_ = cp.quantity_;
      qtyNeeded_ = cp.qtyNeeded_;
      if (cp.name_ != nullptr) {
        name_ = new char[strlen(cp.name_) + 1];
        strcpy(name_, cp.name_);
      }  
    }
    else {
      name_ = nullptr;
    }
    return *this;
  }

  void Good::sku(const char* str) {
  
    strncpy(sku_, str, MAX_SKU_LEN + 1);

  }

  const char*Good::sku()const {
    return sku_;
  }

  void Good::price(double num) {
    price_ = num;
  }

  double Good::price()const {
    return price_;
  }

  void Good::name(const char* str) {
    delete[] name_;
    name_ = new char[strlen(str) + 1];
    strcpy(name_, str);

  }

  const char* Good::name() const {
    return name_;
  }

  void Good::taxed(bool tax) {
    taxed_ = tax;
  }

  bool Good::taxed()const {
    return taxed_;
  }

  void Good::quantity(int qty) {
    quantity_ = qty;
  }

  int Good::quantity()const {
    return quantity_;
  }

  void Good::qtyNeeded(int qtyn) {
    qtyNeeded_ = qtyn;
  }

  int Good::qtyNeeded()const {
    return qtyNeeded_;
  }

  double Good::cost()const {
    if (taxed() == false) {
      return price_;
    }
    else {
      return price_ + (price_*TAX);
      
    }
  }

  bool Good::operator==(const char* str) {
    if (strcmp(str, sku_) == 0) {
      return true;
    }
    else {
      return false;
    }
  }

  int Good::operator+=(int num) {
    quantity_ += num;
    return quantity_;
  }

  double operator+=(double& lnum, const Good& c) {
    //int i = c.quantity;
     return lnum += c.cost() * c.quantity();
  }
  std::ostream& operator << (std::ostream& os, const Good& c) {
    return c.display(os, true);
  }
  std::istream& operator >> (std::istream& is, Good& i) {
    return i.conInput(is);
  }

}