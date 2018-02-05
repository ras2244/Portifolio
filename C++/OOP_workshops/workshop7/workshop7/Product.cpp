#include "Product.h"
#include <iomanip>

namespace w7 {
  double Product::getCharge() const {
    return add;
  }

  void Product::display(std::ostream& os) {

    os << std::setw(10) << std::right << pID << std::setw(10) << std::right << add;

  }
}