// Wedding Planner Application
// File	WPlannercpp
// Version 2.2
// Date	2016/11/15
// Author	Ricardo Leal
// Description
// This program implements the Menu and call each functon to a 
// specific task to perform, List, Add Good to Shelf, Custom made goods
// Update quantity and delete a good.
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <cstring>
#include <iomanip>
#include "WPlanner.h"
#include "Good.h"
#include "OnShelf.h"
#include "CustomMade.h"

using namespace std;
namespace ict {

  /*WPlanner::~WPlanner(){
    delete[] items_;     
  }*/

   WPlanner::WPlanner(const char* filename) {
     int i = 0;
     strncpy(filename_, filename, 255);
     for (i = 0; i < MAX_NO_RECS; i++){
       items_[i] = nullptr;
     }
    
     noOfItems_ = 0;
     loadRecs();


   }
   void WPlanner::saveRecs() {
     int i = 0;
     datafile_.open(filename_, std::ios::out);
    
     for (i = 0; i < noOfItems_; i++){       
       items_[i]->store(datafile_);
     }
     datafile_.close();
   }

   void WPlanner::loadRecs() {
     char tag = '\0';
     int readIndex = 0;
     Good* item=nullptr;
     datafile_.open(filename_, std::ios::in);
     if (datafile_.fail()){
       datafile_.clear();
       datafile_.close();
       datafile_.open(filename_, std::ios::out);
       datafile_.close();
     }
     else{
       while(!datafile_.fail()){       
         datafile_ >> tag;

         if (tag == 'C'){           
           item = new CustomMade;          
         }
         else if (tag == 'O'){                 
           item = new OnShelf;           
         }
         
           datafile_.ignore();                  
           item->load(datafile_);
           items_[readIndex] = item;           
           noOfItems_ = readIndex;
           readIndex++;
       }

       
      datafile_.close();  
      //delete item;
     }
   }
   void WPlanner::getSku(char* sku) {

     cout << "Please enter the SKU: ";
     cin >> sku;
     cout << endl;

     if (cin.fail()){
       cin.clear();
       cin.ignore();
     }

   }
   void WPlanner::deleteItem() {
      //cout << "Not implemented!" << endl << endl;
     char* newSku;
     newSku = new char[MAX_SKU_LEN + 1];
     getSku(newSku);
     char getawn;
     int check = SearchItems(newSku);

     if (check != -1){
       int index = SearchItems(newSku);
       cout << "The following Item will be deleted:" << endl;
       items_[index]->display(cout, false);
       cout << endl << endl << "Type (Y) to confirm or (N) to abort: ";
       cin >> getawn;       
       if (getawn == 'Y' || getawn == 'y'){
         delete items_[index];
         //items_[index] = nullptr;
         for (;index <= noOfItems_ - 1; index++){
           items_[index] = items_[index + 1];
         }
         noOfItems_--;
         saveRecs();
         cout <<endl<< "Item deleted!" << endl << endl;
       }
       else{
         cout << endl<<"Aborted!" << endl << endl;
       }
     }   
     else{
       cout << "Item Not found!" << endl << endl;
     }
     //delete[] newSku;
   }
   void WPlanner::updateQty() {
     int newqty = 0;
     char* newSku;
     newSku = new char[MAX_SKU_LEN + 1];
     getSku(newSku);
     
     int check = SearchItems(newSku);

     if (check!=-1){
       int index = SearchItems(newSku);

       items_[index]->display(cout, false);

       cout << endl << endl <<"Please enter the number of purchased goods: ";
       std::cin >> newqty;
       cout << endl;

       int bal = items_[index]->qtyNeeded() - items_[index]->quantity();

       if (!std::cin.fail()){
         if (newqty <= bal){
           *items_[index] += newqty;
           saveRecs();
           cout << "Updated!" << endl << endl;
         }
         else{
           *items_[index] += bal;
           saveRecs();
           cout << "Too many purchased, only " << bal << " needed, please return the extra " << newqty - bal << "." << endl;
           cout <<endl << "Updated!" << endl <<endl;
         }
       }
       else{
         cout << "Invalid Quantity value!" << endl;
       }
     }
     else{
       cout << endl << "Not found!"<< endl;
     }
     //delete[] newSku;
   }
   void WPlanner::listItems()const {

     int i = 0;
     double totalCost = 0;

      cout << " Row | SKU | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl
         << "-----|-----|--------------------|-------|---|----|----|----------" << endl;

      for (i = 0; i < noOfItems_; i++){
        cout << right << setfill(' ') <<setw(4) << i + 1 << left << " | ";
        items_[i]->display(cout, true);
        cout << endl;
        totalCost += items_[i]->cost() * items_[i]->quantity();
        
      }
      cout << "-----+-----+--------------------+-------+---+----+----+----------" << endl;

      cout << "Total cost of the Wedding: $" << left << setprecision(2) << fixed << totalCost;

      cout << endl<<endl;

   }
   int WPlanner::SearchItems(const char* sku)const {
     int i = 0;
     int index = -1;
     for (i= 0; i < noOfItems_; i++){       
       if (*items_[i]== sku){
         index = i;
       }       
     }

     return index;

   }
   void WPlanner::addItem(bool isCustomMade) {
     Good* temp = nullptr;
     if (isCustomMade == true){
       temp = new CustomMade;
       temp->conInput(cin);       
       if (!cin.fail()){
         items_[noOfItems_] = temp;
         noOfItems_ ++;
         saveRecs();
         cout << endl << "Good added" << endl<<endl;
       }
       else{
         temp->display(cout, true);
       }
     }
     else{
       temp = new OnShelf;
       temp->conInput(cin);
       if (!cin.fail()){
         items_[noOfItems_] = temp;
         noOfItems_++;         
         saveRecs();
         cout << endl << "Good added" << endl<<endl;
       }
       else{
        temp->display(cout, true);
       }
     }

     //delete temp;
   }
   int WPlanner::menu() {
      int selection = -1;
      
      cout << "Wedding Planner Management Program" << endl;
      cout << "1 - List goods" << endl;
      cout << "2 - Add On Shelf Good" << endl;
      cout << "3 - Add Custom-Made Good" << endl;
      cout << "4 - Update Good quantity" << endl;
      cout << "5 - Delete" << endl;
      cout << "0 - Exit program" << endl;
      cout << "> ";
      cin >> selection;
      cout << endl;

      if (std::cin.fail() != true && (selection >= 0 && selection <= 5)){
        cin.ignore();
        cin.clear();
        
        
      }
      else{
        selection = -1;
        cin.ignore();
        cin.clear();
      }
      return selection;
   }
   int WPlanner::run() {
      bool done = false;
      while (!done) {
         switch (menu()) {
         case 1:
           listItems();
            break;
         case 2:
           addItem(false);
            break;
         case 3:
           addItem(true);
            break;
         case 4:
           updateQty();
            break;
         case 5:
           deleteItem();
            break;
         case 0:
            done = true;
            cout << "Goodbye!!" << endl << endl;
            break;
         case -1:
            cout << "===Invalid Selection, try again.===" << endl <<endl ;
            break;
         }
      }
      return 0;
   } // WPlanner::run() end
}


/* outputs

Wedding Planner Management Program
1 - List goods
2 - Add On Shelf Good
3 - Add Custom-Made Good
4 - Update Good quantity
5 - Delete
0 - Exit program
>



Not found!

Please enter the number of purchased goods:

Too many purchased, only 5 needed, please return the extra 15.

Updated!

Not implemented!

*/