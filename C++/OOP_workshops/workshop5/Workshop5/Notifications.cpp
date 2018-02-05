#include <iostream>
#include <fstream>
#include "Notifications.h"
#include "Message.h"

using namespace std;

namespace w5{

  
  Notifications::Notifications(const Notifications& rhs) :messageCount(0), messageTable(nullptr){

    if (rhs.messageTable){
      messageTable = new Message[MAX_MESSAGE];
      for (int i = 0; i < messageCount; i++){
        messageTable[i] = rhs.messageTable[i];
      }
    }
  }
  Notifications& Notifications::operator=(const Notifications& rhs){
    delete[] messageTable;
    messageTable = nullptr;
    messageCount = 0;
    if (rhs.messageTable){
      messageTable = new Message[MAX_MESSAGE];
      for (int i = 0; i < messageCount; i++){
        messageTable[i] = rhs.messageTable[i];
      }
    }

    return *this;
  }
    Notifications::~Notifications(){
      delete[] messageTable;
  }

  Notifications::Notifications(Notifications&& rhs) :messageCount(rhs.messageCount), messageTable(rhs.messageTable){
  //turn rhs into a zombie
    rhs.messageTable = nullptr;
    rhs.messageCount = 0;

  }
  Notifications&& Notifications::operator = (Notifications&& rhs){     
    
    delete[] messageTable;
    messageTable = nullptr;
    messageCount = 0;

    //steal brains
    messageCount = rhs.messageCount;
    messageTable = rhs.messageTable;

    //make zombie
    rhs.messageTable = nullptr;
    rhs.messageCount = 0;

    if (rhs.messageTable){
      messageTable = new Message[MAX_MESSAGE];
      for (int i = 0; i < messageCount; i++){
        messageTable[i] = rhs.messageTable[i];
      }
    }
    return std::move(*this);
  }
  void Notifications::operator += (const Message& msg){
    if (messageTable == nullptr){
      messageTable = new Message[MAX_MESSAGE];   
    }
    if (messageCount < MAX_MESSAGE){
      messageTable[messageCount] = msg;
      messageCount++;
    }
  }
  void Notifications::display(std::ostream& os) const{
    //os << "Notifications\n";
    //os << "=============\n";

    for (int i = 0; i < messageCount; i++){
      messageTable[i].display(os);
    }

  }
}