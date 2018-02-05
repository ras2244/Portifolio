#include <iostream>
#include "CString.h"
#include "Process.h"

using namespace w1;
using namespace std;

int main (int argc, char* argv[]){
	//out<<"number of arguments (argc) is "<<argc<< "\n";
	//for (int arg=0; arg<argc; arg++){
	//cout<<"argv["<<arg<<"] is __>" <<argv[arg]<<"<--\n";
	//}
	
	cout<<"Command line :";
		for (int arg=0; arg<argc; arg++){
			cout<<" "<< argv[arg];
			//cout<<endl;
		}
		
	
	//cout<<"Maximum number of characters stored :" <<num<<"\n";
	
	if(argc==1){
		cerr<<"\ninsuficient numberr of arguments (min 1)\n";
		return 1;
	}
	
	cout<<"\nMaximum number of characters stored :" <<num<<"\n";
		
	for (int arg=1; arg<argc; arg++){
			//cout<<arg -1 << ": ";
			process(argv[arg]);
		}
		
	return 0;
}