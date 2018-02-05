#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "util.h"



//class Item;
//class ItemManager;

class Item {
  std::string itemName, itemInstaller, itemRemover, itemSequence, itemDescription;
public:
  Item(std::vector<std::string> &row);
  void print();
  void graph(std::fstream &os);

};

class ItemManager {
  std::vector<Item> items;
public:
  ItemManager() {}
  ItemManager(std::vector <std::vector<std::string>> &csvData);
  void print();
  void graph(std::string itemFilename);
};

/*
int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string(argv[0]) + " needs two arguments, the csv file name, and the csv sperator character";
    string itemFilename = argv[1];
    char separator = argv[2][0];
    vector <vector<string>> csvData;
    csvReader(itemFilename, separator, csvData);
    //csvPrint(csvData);
    ItemManager im(csvData);

    im.print();
    im.graph(itemFilename);
  }
  catch (const string& e) {
    cerr << e << "\n";
  }
  return 0;
}
*/