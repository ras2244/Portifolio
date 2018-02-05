#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void trimSpaces(string& s){
  //return;
  //delete the first character if it is space
  while (!s.empty() && s[0] == ' '){
    s.erase(0,1);
  }
  //delete the last character if it is space
  while (!s.empty() && s[s.size() -1] == ' '){
    s.erase(s.size() -1,1);
  }

}

void print(vector<vector<string> > csvData){
  // print using indexes
  for (size_t row = 0; row < csvData.size(); row ++){
    cout << "row =" << row << " ";
    for (size_t column = 0; column < csvData[row].size(); column++){
      cout << "<" << csvData[row][column] << "> ";
    }
    cout << endl;
  }
  // print using iterators
  for (auto rowIt = csvData.begin(); rowIt != csvData.end(); rowIt++){
    for (auto columnIt = rowIt->begin(); columnIt!= rowIt->end(); columnIt++){
      cout << "<" << *columnIt << "> ";
    }
    cout << endl;
  }

  // print using range-based for    //ON THE EXAM
  for (auto row : csvData) {
    for (auto column : row) {
      cout << "<" << column << ">";
      //cout << "\n";
    }
    cout << "\n";
  }


}


void csvRead(string& filename, char separator, vector<vector<string> > csvData){

  cout << "filename = '" << filename << endl;
  cout << "separator = '" << separator << endl;

  fstream is(filename, ios::in); {
    if (!is.is_open()){
      throw string("cannot open file") + filename + "'";
    }

    string line;
    while (getline(is, line)){
      auto cr = line.find('\r');
      if (cr != string::npos){
        line.erase(cr);
      }

      cout << "line ==>" << line << "<==\n";
      vector<string> fields;
      string field;
      size_t index = 0;
      int fieldcount = 0;
      while (index < line.size()){
        if (line[index] != separator){
          field += line[index];
        }
        else{
          trimSpaces(field);
          fields.push_back(move(field));//turns field into a zombie
          field.clear();
        }
        index++;
      }
      //index++; // skip separator character
      //cout << "field = " << field << endl;
      //fieldcount++;
      if (!field.empty()){
        trimSpaces(field);
        fields.push_back(move(field));
        csvData.push_back(move(fields));
        fields.clear();
      }
      else{

        for (auto e : fields){
          cout << "[" << e << "] ";
        }
      }
      //csvData.push_back(move(fields)); // turns vector fields into a zombie
    }
    is.close();
  }
}

  int main(int argc, char * argv[]){

    using namespace std;

    try{
      if (argc != 3){
      throw string(argv[0]) + "need two arguments, the csv file name and the csv separator character";
    }

     string filename = argv[1];
     char separator = argv[2][0];
     vector<vector<string> > csvData;
     csvRead(filename, separator, csvData);
     print(csvData);
  }catch(const string& e){
    cerr << e << endl;
  }
  
}



