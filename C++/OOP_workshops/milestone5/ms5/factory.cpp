#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include <algorithm>   // std::find_if
#include "util.h"

using namespace std;

#include "i.h"
#include "o.h"
#include "t.h"

#include "machine.h"

class Factory {
  vector<Machine> machineList;
public:
  // Factory() { }
  Factory(ItemManager& im, OrderManager& om, TaskManager& tm)
  {
    //srand(time(0));  // initialize the random number generator with the time of day clock

    // STEP 1 - load machines into the factory
    for(size_t count = 0; count < tm.size(); count++) {
      machineList.push_back( move( Machine( tm.getTask(count) ) ) );
    }

    int line = 0;
    // for(auto m : machineList) {
      // line++;
      // cout << line << ": " << m.getTaskName() << "\n";
    // }

    // Step 2 - find source machine
    auto FindMachine = [&] (string n) -> Machine* {
      for(size_t i = 0; i < machineList.size(); i++)
        if(machineList[i].getTaskName() == n)
          return &machineList[i];
      return nullptr;
    };
    for(auto m : machineList) {
      string pass = m.getTaskPass();
      if(!pass.empty()) FindMachine(pass) -> IncInComing();

      string fail = m.getTaskFail();
      if(!fail.empty()) FindMachine(fail) -> IncInComing();
    }

    int source = -1;
    for(size_t m = 0 ; m < machineList.size(); m++ ) {
      cout << m << ": " << machineList[m].getTaskName();
      if(machineList[m].isSingleton()) {
        cout << " SINGLETON";
      } else {
        if(machineList[m].isSource()) {
          cout << " SOURCE";
          if(source == -1) {
            source = m;
          } else {
            throw string("Multiple sources.  Fix data and re-submit!");
          }
        }
        if(machineList[m].isSink()) cout << " SINK";
      }
      cout << "\n";
    }
    cout << "Source is " << source << "\n";
    if(source == -1) throw string("NO SOURCE NODE!!! Fix data and re-submit.");

    // STEP 3 - load jobs into inputQ for the source
    for( size_t o = 0; o < om.getSize(); o++) {
      machineList[source].AddJob( Job( om.getOrder(o) ) );
    }

    for(auto m : machineList) {
      cout << m.getTaskName() << " has " << m.inputQSize() << " jobs.\n";
    }

    for(auto &m : machineList) {
      m.Classify(im);
    }
    
    // STEP 4 time loop
    int time = 0;
    while(true) {
      cout << "TIME = " << time << "\n";

      // ARE THERE MACHINES WITH WORK TO DO?
      bool AllDone = true;
      for(auto m : machineList) {
        if(m.inputQSize()) {           // found a machine with some jobs
          AllDone = false;
          break;
        }
      }
      if(AllDone) {
        cout << "All Done\n";
        break; // break out of time loop
      }

      for(auto &m : machineList) { // machine loop
        if(m.inputQSize() == 0) {
          continue; // nothing for this machine to do
        }

        Job job =  m.getJob();

        cout << "'" << m.getTaskName() << "' is looking at job "
             << job.getCustomer() << "/"
             << job.getProduct() << "\n";

        if(m.isSink()) {
          cout << "Job arrived at '" << m.getTaskName() << "' a sink --- nothing to do.\n";
          cout << "Job exiting system\n";
          continue; // machine loop over for this machine
        }

        bool didSomething = false;

        // Are we are an installer?
        if(m.getInstaller()) {
          // does this job need our services?
          cout << "'" << m.getTaskName() << "' is an installer\n";

          // for each item in the order,
          //  if not installed
          //    if the installer name is our name
          //      install the item - call Installer(i,true)
          for(size_t i =0 ; i < job.size(); i++) {
            if(job.Installed(i))  // already installed
              continue; // job item #i is already installed

            string itemName = job.getItem(i);
            Item* itemPtr = im.FindItem(itemName);
            if(m.getTaskName() == itemPtr->getItemInstallerTask()) {
              job.Installed(i,true);  // flag the item as installed
              didSomething = true;
              time++;
              cout << "'" << m.getTaskName() << "' installed '" << itemName << "'\n";
              break;  // all done installing 1 item
            }
          }
          
        }
        // Are we are a remover?
        if(m.getRemover()) {
          // does this job need our services?
          cout << "'" << m.getTaskName() << "' is a remover\n";

          // for each item in the order,
          //  if not installed
          //    if the installer name is our name
          //      remove the item - call Installer(i,false)
          for(int i = job.size() - 1; i >= 0; i-- ) { // need to remove the last item with our name installed - work backward
            if(!job.Installed(i))  // not installed
              continue; // job item #i is not installed

            string itemName = job.getItem(i);
            Item* itemPtr = im.FindItem(itemName);
            if(m.getTaskName() == itemPtr->getItemRemoverTask()) {
              job.Installed(i,false);  // flag the item as removed
              didSomething = true;
              time++;
              cout << "'" << m.getTaskName() << "' removed '" << itemName << "'\n";
              break;  // all done removing 1 item
            }
          }
        }

        auto MovePass = [&] {                  // original MovePass function (IT WORKS)
          string pass = m.getTaskPass();
          cout << "moving job to pass machine '" << pass << "'\n";
          for(auto &m2 : machineList) {
            if(m2.getTaskName() == pass) {
              m2.AddJob(job);
              break;
            }
          }
        };

        auto MoveFail = [&] {                  // original MoveFail function (IT WORKS)
          string fail = m.getTaskFail();
          cout << "moving job to fail machine '" << fail << "'\n";
          for(auto &m2 : machineList) {
            if(m2.getTaskName() == fail) {
              m2.AddJob(job);
              break;
            }
          }
        };

        if(!didSomething) {
          // move job to passed inputQ
          MovePass();
          continue; // end of this machine
        }

        if(m.getTaskFail().empty()) {   // if there is only a Pass task
          // move job to passed inputQ
          MovePass();
          continue; // end of this machine
        }

        // flip a coin (rand() &1 --- test if odd)
        if(rand() & 1) {
          // pass
          // move job to Pass machine inputQ
          MovePass();
          continue; // end of this machine
        } else {
          // fail
          // move job to Fail machine inputQ
          MoveFail();
          continue; // end of this machine
        }

      } // machine loop

    } // time loop

    cout << "Simulation over\n";
    cout << "TIME = " << time << "\n";
  }

};

int main(int argc, char*argv[])
{
  try {
    if(argc != 5) {
      throw string("Usage ") + argv[0] + string(": item order task (the 3 csv files) delimiter-char");
    }

    string filenameItem   = string(argv[1]);     // 1st arg is Item CSV file name.
    string filenameOrder  = string(argv[2]);     // 2nd arg is Order CSV file name.
    string filenameTask   = string(argv[3]);     // 3rd arg is Task CSV file name.
    char   delimiter      = argv[4][0];          // 4th arg, 1st char is delimiter

    vector < vector< string > > csvItemData;
    vector < vector< string > > csvOrderData;
    vector < vector< string > > csvTaskData;

    csvRead(filenameItem,  delimiter, csvItemData);
    csvRead(filenameOrder, delimiter, csvOrderData);
    csvRead(filenameTask,  delimiter, csvTaskData);

    // csvPrint(csvTaskData);

    ItemManager im(csvItemData);
    im.Print();
    im.Graph(filenameItem);

    OrderManager om(csvOrderData);
    om.Print();
    om.Graph(filenameOrder);

    TaskManager tm(csvTaskData);
    tm.Print();
    tm.Graph(filenameTask);

    bool GoodToGo = true;
    cout << "Item integrity check\n";
    try {
      im.IntegrityCheck(tm);
    } catch(string& e) {
      GoodToGo = false;
      cerr << e << "\n";
    }

    cout << "Order integrity check\n";
    try {
      om.IntegrityCheck(im);
    } catch(string& e) {
      GoodToGo = false;
      cerr << e << "\n";
    }


    cout << "Task integrity check\n";
    try {
      tm.IntegrityCheck();
    } catch(string& e) {
      GoodToGo = false;
      cerr << e << "\n";
    }

    if(GoodToGo == false) {
      cerr << "***************************************\n";
      cerr << "* DATA HAS ERRORS.  FIX AND RESUBMIT! *\n";
      cerr << "***************************************\n";
      exit(1);
    }

    cout << "******************************************************\n";
    cout << "* DATA PASSED THE INTEGRITY CHECK AND IS GOOD TO GO! *\n";
    cout << "******************************************************\n";

    Factory factory(im, om, tm);

  } catch (const string& e) {
    cerr << e << "\n";
    return 0;
  }
  return 99;
}
