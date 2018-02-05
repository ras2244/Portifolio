#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace w2{
enum passType {PASS_STUDENT, PASS_ADULT, PASS_COUNT};
class Station{
	string stationName;
	unsigned int passes;
	
public:
	Station(){}
	Station(istream& is){
		string s;
		getline(is,s);
		cout<< "station: s='" << s<<"'\n";
		
		size_t index=0;
		while (index <s.size() && s[index] != ':')
			stationName+= s[index++];
		cout << "Station: stationName='" <<stationName<< "'\n";
		
		if(index < s.size()|| s[index] != ':'){
		cerr << "station record name for" << stationName << "'was not terminated with a ';' \n"		
		exit(3);
		}
		
		int student =0;
		while (index < s.size()){
				if(isdigit(s[index])){
				student =10 * student + (s[index} - '0');
				index ++;
			}else{
				break;
			}	
		}
		cout<< "station: student = " << student << "\n";
		if(index < s.size()|| s[index] != ':'){
		cerr << "student pass cout for '" << student <<"' was not terminated with a ' '\n";		
		exit(4);
		}
		
		int adult =0;
		while (index < s.size()){
				if(isdigit(s[index])){
				adult =10 * adult + (s[index} - '0');
				index ++;
			}else{
				break;
			}	
		}
		cout<< "station: adult = " << adult << "\n";
		
		
//Station() - a default constructor that initializes the instance variables through an initialization list
//void set(const std::string&, unsigned, unsigned) - sets the instance variables to the values received in its parameters
//void update(PassType, int) - updates the number of passes - sold if negative, added if positive
//unsigned inStock(PassType) const - returns the number of passes of the requested type
//const std::string& getName() const - returns a reference to a string object holding the name of the station
void report(){
	count << stationName << ', " 
}
		
};
Class Stations {
	int stationCount;
	Station* stationList;
public:
	~Stations(){
		delete [] stationList;
	}
	stations(char* file) : stationCount (0), stationList(nullptr){
		cout << "file=" <<file<< "\n";
		fstream is(file, ios::in);
		if (!is.is_open()){
			cerr <<"Cannot open file '"<<file<<"'\n";
			exit(2);
		}
		string s;
		getline(is, s)
		cout<<"s='" << s <<"'\n";
		int index =0;
		while (index < s.size()){
				if(isdigit(s[index])){
				stationCount =10 * stationCount + (s[index} - '0');
				index ++;
			}else{
				break;
			}	
		}
		if(index < s.size()|| s[index] != ':'){
		cout << "First record of '" << file <<"' was not terminated with a ';'\n";		
		exit(3);
		}
		
		
		stationList = new Station[stationCount];
		for (int count =0; count<stationCount; count ++)
			stationList=
		
		
		is.close();
	}
     void update(){
	 
	 }
     Void restock(){
	 
	 }
     void report(){
	 
	 }
};//class Station
}//namespace