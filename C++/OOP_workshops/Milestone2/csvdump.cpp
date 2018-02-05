//NOT NEEDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

int main(int argc, char* argv[]) {
	try {
		if (argc != 3)
			throw string("Usage: ") + argv[0] + "csv-data-file csv-separator-character";
		string fileName = argv[1];
		char separator = argv[2][0];

		vector< vector<string> > csvData;
		csvRead(fileName, separator, csvData);
		csvPrint(csvData);

	}
	catch (const string& e) {
		cerr << e << "\n";
	}

}