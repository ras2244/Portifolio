#include <iostream>
#include <fstream>
#include <vector> 
#include <string>

#include "util.h"

using namespace std;

void trim(string& s)
{
  while(s.size() > 0 && s[0] == ' ')  // kill leading spaces
     s.erase(0,1);
  while(s.size() > 0 && s[s.size()-1] == ' ')  // kill leading spaces
     s.erase(s.size()-1,1);
}

void csvPrint(vector < vector< string > > & csvData)
{
  cout << "\nindex [] print\n";
  for(size_t row = 0; row < csvData.size(); row++) {
    cout << "row " << row << " ";
    cout << "(" << csvData[row].size() << " fields) ";
    for(size_t column = 0; column < csvData[row].size(); column++) {
      cout << "[" << csvData[row][column] << "] ";
    }
    cout << "\n";
  }

  cout << "\niterator print\n";
  for(auto rowIt = csvData.begin(); rowIt != csvData.end(); rowIt++) {
    cout << "row " << rowIt - csvData.begin() << " ";
    cout << "(" << rowIt -> size() << " fields) ";
    for(auto columnIt = rowIt->begin(); columnIt != rowIt->end(); columnIt++) {
      cout << "{" << *columnIt << "} ";
    }
    cout << "\n";
  }

  cout << "\nrange-based for print\n";
  for(auto row : csvData) {
    cout << "(" << row.size() << " fields) ";
    for(auto column : row) {
      cout << "<" << column << "> ";
    }
    cout << "\n";
  }

}

void csvRead(string& filename, char delimiter, vector < vector< string > > & csvData)
{
  fstream is( filename, ios::in);
  if( not is.is_open())
    throw string("Canot open file ") + filename ;

  string line;
  while( getline(is, line)) {
    auto cr = line.find('\r');
    if(cr != string::npos)
      line.erase(cr);
    // cout << "line -->" << line << "<--\n";

    vector <string> fields;
    string field;
    size_t i = 0;

    while(i < line.size() ) {
      if(line[i] != delimiter) {
        field += line[i];
      } else {
        trim( field );
        fields.push_back( move(field) );
      }
      i++;
    }
    // what if the last entry was not a 'delimiter' character?
    if( not field.empty()) {
      trim( field );
      fields.push_back( move(field) );
    }

    csvData.push_back( move(fields) );
  }

  is.close();
}

bool validItemName(string&t)
{
  if(t.empty()) return false;

  for(auto c : t) {
    if(not (isalnum(c) || c == ' ' || c == '_') )
      return false;
  }
  return true;
}

bool validItemSequence(string&t)
{
  if(t.empty()) return false;

  for(auto c : t) {
    if(not isdigit(c))
      return false;
  }
  return true;
}

bool validOrderCustomerName(string&t)
{
  if(t.empty()) return false;

  for(auto c : t) {
    if(not (isalnum(c) || c == ' ' || c == '\'' || c == '-') ) 
      return false;
  }
  return true;
}

bool validOrderProductName(string&t)
{
  if(t.empty()) return false;

  for(auto c : t) {
    if(not (isalnum(c) || c == ' ' || c == '_') )
      return false;
  }
  return true;
}

bool validTaskName(string&t)
{
  if(t.empty()) return false;

  for(auto c : t) {
    if(not (isalnum(c) || c == ' ' || c == '_') )
      return false;
  }
  return true;
}

bool validSlotName(string&t)
{
  if(t.empty()) return false;

  for(auto c : t) {
    if(not isdigit(c))
      return false;
  }
  return true;
}
