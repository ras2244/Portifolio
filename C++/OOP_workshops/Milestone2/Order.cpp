#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "util.h"

using namespace std;

class Order;
class OrderManager;

class Order {
  string OrderCustome, OrderSlots, OrderPass, OrderFail;

public:
  Order() : OrderSlots("1") {} //not needed

  Order(std::vector<std::string> &row) : OrderSlots("1")
  {
    switch (row.size()) {
    case 4:
      if (validOrderName(row[3]))
        OrderFail = row[3];
      else
        throw string("Expected a fail Order name, found '") + row[3] + "'";
    case 3:
      if (validOrderName(row[2]))
        OrderPass = row[2];
      else
        throw string("Expected a pass Order name, found '") + row[2] + "'";
    case 2:
      if (validSlots(row[1]))
        OrderSlots = row[1];
      else
        throw string("Expected a slots, found '") + row[1] + "'";
    case 1:
      if (validOrderName(row[0]))
        OrderName = row[0];
      else
        throw string("Expected a Order name, found '") + row[0] + "'";
      break;
    default:
      throw string("Expected 1, 2, 3 or 4 fields - found ") + to_string(row.size());
    }
  } // end Order class

  void print() {
    cout << "Order:  /Customer/Product/Items: "
      << "/" << OrderName
      << "/" << OrderSlots
      << "/" << OrderPass
      << "/" << OrderFail
      << "/\n";
  }

  void graph(fstream& os) {
    string q = "\"";
    if (!OrderPass.empty()) {
      os << q << OrderName << q << " -> " << q << OrderPass << q << "[color=green];\n";
    }
    if (!OrderFail.empty()) {
      os << q << OrderName << q << " -> " << q << OrderFail << q << "[color=red];\n";
    }
    if (OrderPass.empty() && OrderFail.empty()) {
      os << q << OrderName << q << ";\n";
    }
  }

};

class OrderManager {
  vector< Order > OrderList;
public:
  OrderManager(std::vector< std::vector <std::string> > &csvData)
  {
    for (auto& row : csvData) {
      try {
        OrderList.push_back(move(Order(row)));
      }
      catch (const string& e) {
        cerr << e << "\n";
      }
    }
  }

  void print() {
    for (auto t : OrderList) {
      t.print();
    }
  }

  void graph(string& fileName) {
    string f = fileName + ".gv";
    fstream os(f, ios::out | ios::trunc);

    os << "digraph OrderGraph {\n";

    for (auto t : OrderList) {
      t.graph();
    }

    os << "}\n";

    os.close();

    string cmd = string("dot -Tpng ") + fileName + ".gv > " + fileName + ".gv.png";
    cout << cmd << " returned " << system(cmd.c_str()) << "\n";
  }

}; // end OrderManager class

int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + "csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector< vector<string> > csvData;

    csvRead(fileName, separator, csvData);
    //csvPrint(csvData);

    OrderManager om(csvData);

    om.print();
    om.graph(fileName);
  }
  catch (const string& e) {
    cerr << e << "\n";
  }
}
