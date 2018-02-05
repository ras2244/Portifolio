#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "T.h"

using namespace std;

//class Task;
//class TaskManager;

  Task::Task(std::vector<std::string> &row) : taskSlots("1")
  {
    switch (row.size()) {
    case 4:
      if (validTaskName(row[3]))
        taskFail = row[3];
      else
        throw string("Expected a fail task name, found '") + row[3] + "'";
    case 3:
      if (validTaskName(row[2]))
        taskPass = row[2];
      else
        throw string("Expected a pass task name, found '") + row[2] + "'";
    case 2:
      if (validSlots(row[1]))
        taskSlots = row[1];
      else
        throw string("Expected a slots, found '") + row[1] + "'";
    case 1:
      if (validTaskName(row[0]))
        taskName = row[0];
      else
        throw string("Expected a task name, found '") + row[0] + "'";
      break;
    default:
      throw string("Expected 1, 2, 3 or 4 fields - found ") + to_string(row.size());
    }
  } // end Task class

  void print() {
    cout << " /Name/Slots/Pass/Fail/ = "
      << "/" << taskName
      << "/" << taskSlots
      << "/" << taskPass
      << "/" << taskFail
      << "/\n";
  }

  void graph(fstream& os) {
    string q = "\"";
    if (!taskPass.empty()) {
      os << q << taskName << q << " -> " << q << taskPass << q << "[color=green];\n";
    }
    if (!taskFail.empty()) {
      os << q << taskName << q << " -> " << q << taskFail << q << "[color=red];\n";
    }
    if (taskPass.empty() && taskFail.empty()) {
      os << q << taskName << q << ";\n";
    }
  }

};

class TaskManager {
  vector< Task > taskList;
public:
  TaskManager(std::vector< std::vector <std::string> > &csvData)
  {
    for (auto& row : csvData) {
      try {
        taskList.push_back(move(Task(row)));
      }
      catch (const string& e) {
        cerr << e << "\n";
      }
    }
  }

  void print() {
    for (auto t : taskList) {
      t.print();
    }
  }

  void graph(string& fileName) {
    string f = fileName + ".gv";
    fstream os(f, ios::out | ios::trunc);

    os << "digraph taskGraph {\n";

    for (auto t : taskList) {
      t.graph();
    }

    os << "}\n";

    os.close();

    string cmd = string("dot -Tpng ") + fileName + ".gv > " + fileName + ".gv.png";
    cout << cmd << " returned " << system(cmd.c_str()) << "\n";
  }

}; // end TaskManager class

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