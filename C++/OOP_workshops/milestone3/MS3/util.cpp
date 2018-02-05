#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "util.h"


void trim(std::string& s) {
	while (!s.empty() && s[0] == ' ') {
		s.erase(0, 1); // delete 1st character
	}
	while (!s.empty() && s[s.size() - 1] == ' ') {
		s.erase(s.size() - 1, 1); //delete last character
	}
}

void csvRead(std::string& fileName, char separator, std::vector< std::vector<std::string> > &csvData) {
	//vector< vector<string> > csvData;

	std::fstream is(fileName, std::ios::in);
	if (!is.is_open())
		throw std::string("Cannot open the file '") + fileName = "'";

	std::string line;

	while (getline(is, line)) {
		// handle any CR '\r' in data
		auto cr = line.find('\r');
		//cout << line << "\n";
		if (cr != std::string::npos)
			line.erase(cr);

		//cout << line << "\n";

		size_t index = 0;
		std::string field;
		std::vector<std::string> fields;

		while (index < line.size()) {

			while ((index < line.size()) && (line[index] != separator)) {
				field += line[index];
				index++;
			}
			//cout << field << "\n";
			index++; //skip separator

			trim(field); //get rid of spaces
			fields.push_back(move(field));
		}
		for (auto e : fields) {
			std::cout << "[" << e << "] ";
		}
		std::cout << "\n";

		csvData.push_back(move(fields));
	}
	is.close();
}

void csvPrint(std::vector<std::vector<std::string> > &csvData) {
	for (auto row : csvData) {
		for (auto column : row) {
			std::cout << "<" << column << "> ";
		}
		std::cout << "\n";
	}

	for (auto row = csvData.begin(); row != csvData.end(); row++) {
		for (auto column = row->begin(); column != row->end(); column++) {
      std::cout << "<" << *column << "> ";
		}
		std::cout << "\n";
	}

	for (size_t row = 0; row < csvData.size(); row++) {
		for (size_t column = 0; column < csvData[row].size(); column++) {
			std::cout << "{" << csvData[row][column] << "} ";
		}
		std::cout << "\n";
	}
}

bool validTaskName(std::string &s) {
	for (auto c : s)
  if (!(isalpha(c) || c == ' ')) //is alpha numeric function
			return false;
	return true;
}

bool validSlots(std::string &s){
  for (auto c : s)
  if (!(isalpha(c) || c == ' ')) //is alpha numeric function
    return false;
  return true;
}
  bool validItem(std::string &s){
    for (auto c : s)
    if (!(isalpha(c) || c == ' ')) //is alpha numeric function
      return false;
    return true;
}

  bool validSequence(std::string &s){
    for (auto c : s)
    if (!(isdigit(c) || c == ' ')) //is alpha numeric function
      return false;
    return true;
  }

  bool validTask(std::string &s){
    for (auto c : s)
    if (!(isalpha(c) || c == ' ')) //is alpha numeric function
      return false;
    return true;
  }
