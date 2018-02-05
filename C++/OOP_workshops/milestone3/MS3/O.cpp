#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "O.h"

using namespace std;
//class Order;
//class OrderManager;


  Order::Order(vector<string> &row) {

    //for (auto e : row)
    //cout << "~" << e << "~ ";
    //cout << "\n";

    if (row.size() < 3)
      throw string("Expected at least three fields for an order: customer, product, and at least one item- found") + to_string(row.size());
    orderCustomer = row[0];
    orderProduct = row[1];

    for (size_t field = 2; field < row.size(); field++)
    if (validItem(row[field]))
      orderItems.push_back(row[field]);
    else
      throw string("Expected valid item name  - found '") + row[field] + "'";
  }
  void Order::print() {
    cout << "order: customer/product/items... /"
      << orderCustomer << "/"
      << orderProduct << "/";
    for (auto i : orderItems)
      cout << i << "/";
    cout << "\n";
  }
  void Order::graph(std::fstream &os) {

    string q("\"");
    for (auto i : orderItems) {
      os << q + orderCustomer + "/" + q + orderProduct + q + i + q + "[color=blue];\n";

    }

  }




  OrderManager::OrderManager(vector <vector<string>> &csvData) {
    for (auto row : csvData) {
      try {
        orders.push_back(move(Order(row)));
      }
      catch (const string& e) {
        cerr << "OrderManager: problem " << e << "\n";
      }
    }
  }
  void OrderManager::print() {
    for (auto t : orders) {
      t.print();
    }
  }
  void OrderManager::graph(std::string orderFilename) {

    string dotFile = orderFilename + ".gv";
    std::fstream os(dotFile, std::ios::out | std::ios::trunc);
    os << "diagraph orderGraph {\n";
    for (auto t : orders)
      t.graph(os);
    os << "}\n";
    os.close();
    string cmd = "dot -Tpng " + orderFilename + ".gv > " + orderFilename + ".gv.png";
    cout << cmd << " returned " << system(cmd.c_str());

  }

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