/*************************************************
 * Program Filename: StorageCloset.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The StorageCloset class header file.
 * **********************************************/


#ifndef STORAGECLOSET_HPP
#define STORAGECLOSET_HPP

#include "Room.hpp"

class StorageCloset : public Room
{
private:
  bool lightState;
public:
  StorageCloset(int,int);
  virtual void special(int, Container*, int*);
  virtual void printActionList();
  virtual ~StorageCloset();
};

#endif
