#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "util.h"

using namespace std;

class Item;
class ItemManager;

class Item {
  string itemDescription, itemInstaler, itemSequence, itemName;

public:
  Item() : itemSlots("1") {} //not needed

  Item(std::vector<std::string> &row) : itemSlots("1")
  {
    switch (row.size()) {
    case 5:
      itemDescription = row[4];
    case 4:
      if (validItem(row[0]))
        itemPass = row[0];
      else
        throw string("Expected a pass item , found '") + row[0] + "'";
    
      if (validSlots(row[1]))
        itemSlots = row[1];
      else
        throw string("Expected a slots, found '") + row[1] + "'";
    
      if (validItemName(row[0]))
        itemName = row[0];
      else
        throw string("Expected a item name, found '") + row[0] + "'";
      break;
    default:
      throw string("Expected 1, 2, 3 or 4 fields - found ") + to_string(row.size());
    }
  } // end Item class

  void print() {
    cout << " /Name/Slots/Pass/Fail/ = "
      << "/" << itemName
      << "/" << itemSlots
      << "/" << itemPass
      << "/" << itemFail
      << "/\n";
  }

  void graph(fstream& os) {
    string q = "\"";
    if (!itemPass.empty()) {
      os << q << itemName << q << " -> " << q << itemPass << q << "[color=green];\n";
    }
    if (!itemFail.empty()) {
      os << q << itemName << q << " -> " << q << itemFail << q << "[color=red];\n";
    }
    if (itemPass.empty() && itemFail.empty()) {
      os << q << itemName << q << ";\n";
    }
  }

};

class ItemManager {
  vector< Item > itemList;
public:
  ItemManager(std::vector< std::vector <std::string> > &csvData)
  {
    for (auto& row : csvData) {
      try {
        itemList.push_back(move(Item(row)));
      }
      catch (const string& e) {
        cerr << e << "\n";
      }
    }
  }

  void print() {
    for (auto t : itemList) {
      t.print();
    }
  }

  void graph(string& fileName) {
    string f = fileName + ".gv";
    fstream os(f, ios::out | ios::trunc);

    os << "digraph itemGraph {\n";

    for (auto t : itemList) {
      t.graph();
    }

    os << "}\n";

    os.close();

    string cmd = string("dot -Tpng ") + fileName + ".gv > " + fileName + ".gv.png";
    cout << cmd << " returned " << system(cmd.c_str()) << "\n";
  }

}; // end ItemManager class

int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + "csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector< vector<string> > csvData;

    csvRead(fileName, separator, csvData);
    //csvPrint(csvData);

    ItemManager tm(csvData);

    tm.print();
    tm.graph(fileName);
  }
  catch (const string& e) {
    cerr << e << "\n";
  }
}
