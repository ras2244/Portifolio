#include <iostream>
#include <fstream>
#include <vector> 
#include <string>
#include "util.h"

using namespace std;

int main(int argc, char*argv[])
{
  try {
    if(argc != 3) {
      throw string("Usage ") + argv[0] + string(": filename delimiter-char");
    }

    string filename  = string(argv[1]);     // 1st arg is filename
    char   delimiter = argv[2][0];  // 2nd arg, 1st char is delimiter

    vector < vector< string > > csvData;
    csvRead(filename, delimiter, csvData);

    csvPrint(csvData);

  } catch (const string& e) {
    cerr << e << "\n";
  }
}
