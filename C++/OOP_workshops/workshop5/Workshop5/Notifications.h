#pragma once
#include <iostream>
#include "Message.h"

namespace w5{

  const int MAX_MESSAGE = 10;
  class Notifications{    
    int messageCount;
    Message* messageTable;
  public:

    Notifications(){//- default constructor - empty 
      messageCount = 0;
      messageTable = nullptr;
    }    
    Notifications(const Notifications&);// - copy constructor
    Notifications& operator=(const Notifications&); //-copy assignment operator
    Notifications(Notifications&&); // - move constructor
    Notifications&& operator=(Notifications&&);//-move assignment operator
    ~Notifications(); // - destructor
    void operator+=(const Message& msg); // -adds msg to the set
    void display(std::ostream& os) const; // -inserts the Message objects to the os output stream



  };//class

}//namespace
