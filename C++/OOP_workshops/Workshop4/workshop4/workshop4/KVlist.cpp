//#include <iostream>
//#include <iomanip>
//#include <string>
//#include "KVlist.h"
//
//using namespace std;
//
//
//template <typename K, typename V, size_t SIZE>
//
//size_t KVList::size()const{ 
//  return tableSize;
//}
//
//template <typename K, typename V, size_t SIZE>
//
//const K& KVList::key(int i) const{ 
//
//  if (i >= 0 && i < tableSize){
//    return K[i];
//  }
//
//}
//
//template <typename K, typename V, size_t SIZE>\
//
//const V& KVList::value(int i) const{
//    return V[i];
//  }
//
//  template <typename K, typename V, size_t SIZE>
//
//  KVList& KVList::add(const K&, const V&){ 
//    if (tableSize < SIZE){
//      K[TableSize] = kk;
//      V[TableSize] = vv;
//      tableSize++;
//    }
//    return *this;
//  }
//  template <typename K, typename V, size_t SIZE>
//
//    int KVList::find(const K& k) const{
//      for (size_t i = 0; i < tableSize; i++){
//        if (K[i] == K){
//          return i;
//        }
//      }
//        return 0;
//    }
//
//template <typename K, typename V, size_t SIZE>
//
// KVList& KVList::replace(int i, const K& kk, const V& vv){
//        if (i >= 0; && i < tableSize){
//          k[i] = kk;
//          v[i] = vv;
//        }
//
//   return *this;
//}
//