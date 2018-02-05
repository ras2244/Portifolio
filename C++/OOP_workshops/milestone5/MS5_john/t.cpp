#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <cstring>   // strcasecmp
#include "util.h"

// using namespace std;
#include "t.h"


  Task::Task( std::vector<std::string> row)
    : taskSlots("1")
  {
    switch( row.size() ) {
    case 4:
      if(validTaskName( row[3] ))
        taskFail = row[3];
      else
        throw std::string("expected fail task name, found [") + row[3] + "]";
    case 3:
      if(validTaskName( row[2] ))
        taskPass = row[2];
      else
        throw std::string("expected fail task name, found [") + row[2] + "]";
    case 2:
      if(validSlotName( row[1] ))
        taskSlots = row[1];
      else
        throw std::string("expected fail task name, found [") + row[2] + "]";
    case 1:
      if(validTaskName( row[0] ))
        taskName = row[0];
      else
        throw std::string("expected fail task name, found [") + row[0] + "]";
      break;
    default:
      throw std::string("expected 1,2,3, or 4 fields, found - ") + to_string(row.size());
    }
  }
  void Task::Print()
  {
    cout << "[" << taskName << "] "
         << "[" << taskSlots << "] "
         << "[" << taskPass << "] "
         << "[" << taskFail << "]\n";
  }
  void Task::Graph( fstream& os )
  {
    if(not taskFail.empty() )
      os << '"' << taskName << '"' 
         << "->" 
         << '"' << taskFail << '"' 
         << "[color=red];\n";
    if(not taskPass.empty() )
      os << '"' << taskName << '"' \
         << "->" << '"' << taskPass << '"' \
         << "[color=green];\n";
    if(taskFail.empty() and taskPass.empty() )
      os << '"' << taskName << '"' 
         << ";\n";
  }

  TaskManager::TaskManager( std::vector < std::vector< std::string > > & csvData)
  {
    int lineNumber = 0;
    for(auto row : csvData) {
      try {
        lineNumber++;
        taskList.push_back( move(Task(row)) );
      } catch(std::string& e) {
        cerr << "Problem with line " << lineNumber << ": " << e << "\n";
      }
    }
  }
  void TaskManager::Print()
  {
    int lineNumber = 0;
    for(auto t : taskList) {
        lineNumber++;
        cout << lineNumber << ": ";
        t.Print();
    }
  }
  void TaskManager::Graph(std::string& filename)
  {
    fstream os(filename + ".gv", ios::out);
    if(os.is_open()) {

      os << "digraph taskgraph {\n";
      for(auto t : taskList) {
        t.Graph(os);
      }
      os << "}\n";
      os.close();

      std::string cmd;
      #ifdef __MSVC
        cmd = "C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe"
      #else
        cmd = "dot";
      #endif
      cmd += std::string(" -Tpng ") + filename + ".gv >" +filename + ".gv.png";
      cout << "running " << cmd << "\n";
      cout << "returned " << system(cmd.c_str()) << " <-- 0 is good because it means dot worked!\n";
    }
  }

  Task* TaskManager::FindTask(std::string& name)
  {
    for(size_t t = 0; t < taskList.size(); t++) {
      if(taskList[t].getTaskName() == name)                                       // case matters
      // if(strcasecmp(taskList[t].getTaskName().c_str(),  name.c_str()) == 0)    // if ignoring case
        return &taskList[t];
    }
    return nullptr; // not found
  }

  void TaskManager::IntegrityCheck()
  {

    for(auto t : taskList) {
      if(not t.getTaskPass().empty() && FindTask(t.getTaskPass()) == nullptr) {
        throw std::string("Task '") + t.getTaskName() + "' references Pass task '" + t.getTaskPass() + "' but it does not exist!";
      }
      if(not t.getTaskFail().empty() && FindTask(t.getTaskFail()) == nullptr) {
        throw std::string("Task '") + t.getTaskName() + "' references Fail task '" + t.getTaskFail() + "' but it does not exist!";
      }


    }

  }
