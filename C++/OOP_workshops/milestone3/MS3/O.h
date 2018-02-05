#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;
//class Order;
//class OrderManager;

class Order {
  string orderCustomer, orderProduct;
  vector<string> orderItems;
public:
  Order(vector<string> &row);
  void print();
  void graph(std::fstream &os);
};

class OrderManager {
  vector<Order> orders;
public:
  OrderManager() {}
  OrderManager(vector <vector<string>> &csvData);
  void print();
  void graph(std::string orderFilename);
};

/*
int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string(argv[0]) + " needs two arguments, the csv file name, and the csv sperator character";
    string orderFilename = argv[1];
    char separator = argv[2][0];
    vector <vector<string>> csvData;
    csvReader(orderFilename, separator, csvData);
    //csvPrint(csvData);
    OrderManager om(csvData);

    om.print();
    om.graph(orderFilename);
  }
  catch (const string& e) {
    cerr << e << "\n";
  }
  return 0;
}
*/