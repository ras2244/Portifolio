#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "I.h"


using namespace std;
//class Item;
//class ItemManager;


  Item::Item(vector<string> &row) {
    for (auto e : row)
      //cout << "~" << e << "~ ";
      //cout << "\n";
      switch (row.size()) {
      case 5:
        itemDescription = row[4];

      case 4:
        if (validItem(row[0]))
          itemName = row[0];
        else
          throw string("expected a item name, found '") + row[0] + "'";
        // fall through to 3 field case
        if (validTask(row[1]))
          itemInstaller = row[1];
        else
          throw string("expected a item name, found '") + row[2] + "'";
        // fall through to 2 field case
        if (validTask(row[2]))
          itemRemover = row[2];
        else
          throw string("expected a item name, found '") + row[1] + "'";
        // fall through to 1 field case
        if (validSequence(row[3]))
          itemSequence = row[3];
        else
          throw string("expected a item name, found '") + row[1] + "'";
        break;
      default:
        throw string("Found ") + to_string(row.size()) + " fields, expected 1,2,3, or 4";


    }
  }
  void Item::print() {
    cout << "item: name/installer/remover/squence/description = "
      << itemName << "/"
      << itemInstaller << "/"
      << itemRemover << "/"
      << itemSequence << "/"
      << itemDescription << "/"
      << "\n";
  }
  void Item::graph(std::fstream &os) {

    string q("\"");

    os << q + "Item:" + itemName + q + "->" + q + "Installer:" + itemInstaller + q + "[color=green];\n";

    os << q + "Item:" + itemName + q + "->" + q + "Remover: " + itemRemover + q + "[color=red];\n";


  }



  ItemManager::ItemManager(vector <vector<string>> &csvData) {
    for (auto row : csvData) {
      try {
        items.push_back(move(Item(row)));
      }
      catch (const string& e) {
        cerr << "ItemManager: problem " << e << "\n";
      }
    }
  }
  void ItemManager::print() {
    for (auto t : items) {
      t.print();
    }
  }
  void ItemManager::graph(std::string itemFilename) {
    string dotFile = itemFilename + ".gv";
    std::fstream os(dotFile, std::ios::out | std::ios::trunc);
    os << "diagraph itemGraph {\n";
    for (auto t : items)
      t.graph(os);
    os << "}\n";
    os.close();
    string cmd = "dot -Tpng " + itemFilename + ".gv > " + itemFilename + ".gv.png";
    cout << cmd << " returned " << system(cmd.c_str());
  }


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