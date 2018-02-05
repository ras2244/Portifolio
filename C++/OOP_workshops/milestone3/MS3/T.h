#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

//class Task;
//class TaskManager;

class Task {
  string taskName, taskSlots, taskPass, taskFail;

public:
  Task() : taskSlots("1") {} //not needed

  Task(std::vector<std::string> &row);  

  void print();

  void graph(fstream& os);

};

class TaskManager {
  vector< Task > taskList;
public:
  TaskManager(std::vector< std::vector <std::string> > &csvData);


  void print();

  void graph(string& fileName);
}; // end TaskManager class

/*

int main(int argc, char* argv[]) {
  try {
    if (argc != 3)
      throw string("Usage: ") + argv[0] + "csv-data-file csv-separator-character";
    string fileName = argv[1];
    char separator = argv[2][0];

    vector< vector<string> > csvData;

    csvRead(fileName, separator, csvData);
    //csvPrint(csvData);

    TaskManager tm(csvData);

    tm.print();
    tm.graph(fileName);
  }
  catch (const string& e) {
    cerr << e << "\n";
  }
}
*/