#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

using namespace std;

namespace w5{

  Message::Message(std::ifstream& in, char c){
    std::string line;
    getline (in, line, c);    
    size_t index = 0;
    
    while (index < line.size()){   
       if (line[index] == ' '){
        break;
       }
       name += line[index];
       index++;                   
      } 

      index++; //skip space
 
      if (index < line.size() && line[index] == '@'){
        index++; //skip the @
        while (index < line.size()){
          if (line[index] == ' '){
            break;
          }
          reply += line[index];
          index++;
        }
          //std::cout << "reply -->" << reply << endl;
          index++; // skip the space
        

      }
      while (index < line.size()){
        tweed += line[index];
        index++;
      }
    
  }


  bool Message::empty() const{

   tweed.empty();

   return 0;

  }

  void Message::display(std::ostream& os) const{
    if (!tweed.empty()){
      os << endl;
      os << "Message\n";
      os << "User : " << name << endl;
      if (!reply.empty()){
        os << "Reply : " << reply << endl;
      }
      if (!tweed.empty()){
        os << "Tweet : " << tweed << endl;
      }
    }
  }


}//namespace