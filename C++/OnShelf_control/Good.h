#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict{
	class Good :public ReadWritable {
    private:
      char sku_[MAX_SKU_LEN + 1];
      char* name_;
      double price_;
      bool taxed_;
      int quantity_;
      int qtyNeeded_;
    public:
      Good();
      Good(const char* sku, const char* name, double price, int qty, bool tax=true);
      Good(const Good& cp);
      Good& operator=(const Good& c);      
      virtual ~Good();
      void sku(const char* str);
      void price(double num);
      void name(const char* str);
      void taxed(bool tax);
      void quantity(int qty);
      void qtyNeeded(int qtyn);
      const char* sku() const;
      double price() const;
      const char* name() const; 
      bool taxed() const;
      int quantity() const;
      int qtyNeeded() const;
      double cost()const;
      bool operator==(const char*);
      int operator+=(int num);
	  };

  double operator+=(double&, const Good&);
  std::ostream& operator<<(std::ostream& os,const Good& c);
  std::istream& operator>>(std::istream& is, Good& i);
}


#endif