#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "iProduct.h"
#include "Sale.h"

namespace w7 {
  Sale::Sale(const char* f) {
    std::ifstream file(f);
    while (file.good())	{
      iProduct* ip = readProduct(file);
      productList.push_back(ip);
    }
    productList.pop_back();
  }

  void Sale::display(std::ostream& os)	{
    float sum = 0;
    os << "Product No     Cost Taxable\n\n";  
    for (auto p : productList){
      os << *p;
      sum += p->getCharge();
    }
    os << "\n";
    os << std::setw(10) << "Total" << std::right << std::setw(11) << std::right << std::fixed << std::setprecision(2) << sum << '\n';
    
  }
}