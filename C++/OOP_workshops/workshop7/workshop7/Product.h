#pragma once

#include "iProduct.h"
#include <iomanip>
namespace w7{

  class Product : public iProduct
  {
  private:
    Product* prod;
    long pID;
    double add;
  public:
    Product() : pID(0), add(0.0), prod(nullptr){}
    Product(long id, double value) : pID(id), add(value) {}
    double getCharge() const;    
    void display(std::ostream& os);
    ~Product() {}
  };

}



