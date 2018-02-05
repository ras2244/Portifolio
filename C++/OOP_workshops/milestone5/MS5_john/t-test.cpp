#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include "util.h"

using namespace std;

#include "t.h"

int main(int argc, char*argv[])
{
  try {
    if(argc != 3) {
      throw string("Usage ") + argv[0] + string(": filename delimiter-char");
    }

    string filename  = string(argv[1]);     // 1st arg is filename
    char   delimiter = argv[2][0];  // 2nd arg, 1st char is delimiter

    vector < vector< string > > csvTaskData;
    csvRead(filename, delimiter, csvTaskData);

    // csvPrint(csvTaskData);

    TaskManager tm(csvTaskData);
    tm.Print();
    tm.Graph(filename);

  } catch (const string& e) {
    cerr << e << "\n";
  }
}
