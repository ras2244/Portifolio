#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "iProduct.h"

namespace w7 {
  class Sale {
  private:
    std::vector<iProduct*> productList;
  public:
    Sale(const char*);
    void display(std::ostream&);
  };
}
