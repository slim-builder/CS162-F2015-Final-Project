/*************************************************
 * Program Filename: LoadingDock.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The LoadingDock class header file.
 * **********************************************/


#ifndef LOADINGDOCK_HPP
#define LOADINGDOCK_HPP

#include "Room.hpp"

class LoadingDock : public Room
{
private:
  bool truckState;
  bool meatState;
  bool vegetableState;
public:
  LoadingDock(int);
  virtual void special(int, Container*, int*);
  virtual void printActionList();
  virtual ~LoadingDock();
};

#endif
