#include <iostream>
#include <fstream>
#include <iomanip>
#include "iProduct.h"

namespace w7 {
  Product::Product(const int i, const double c) {
    id = i;
    cost = c;
  }


  double Product::getCharge() const {
    return cost;
  }

  void Product::display(std::ostream& os) const {
    os << std::setw(10) << std::right;
    os << id;
    os << std::setw(10) << std::right;
    os << cost << '\n';
  }


  TaxableProduct::TaxableProduct(const int i, const double c, const char t) {
    id = i;
    cost = c;
    tax = t;
  }

  double TaxableProduct::getCharge() const {
    double fee = 1;
    if (tax == 'H') fee = 1.13;
    if (tax == 'P') fee = 1.08;
    return cost*fee;
  }

  void TaxableProduct::display(std::ostream& os) const {
    os << std::setw(10) << std::right << id << std::setw(10) << std::right << cost;
    os << ' ';
    if (tax == 'H') os << "HST";
    if (tax == 'P') os << "PST";
    os << '\n';
  }


  std::ostream& operator<<(std::ostream& os, const iProduct& p) {
    p.display(os);
    return os;
  }

  iProduct* readProduct(std::ifstream& is) {
    int _Id;
    double _Price;
    char _Tax;
    iProduct* temp;    
    is >> _Id >> _Price;
    if (is.get() != '\n') {
      is.get(_Tax);
      temp = new TaxableProduct(_Id, _Price, _Tax);
    }
    else{ temp = new Product(_Id, _Price); }
    return temp;
  }
}