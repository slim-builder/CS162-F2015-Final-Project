/*************************************************
 * Program Filename: Room.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Room class header file.
 * **********************************************/


#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Container.hpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Room
{
protected:
  Room *north;
  Room *south;
  Room *east;
  Room *west;
  Container *container;
  bool roomState;
  bool payRaiseState[3];
  string name;

public:
  Room();
  virtual void special(int, Container*, int*) = 0;
  virtual void printActionList() = 0;
  void printNavigationList();
  Room *getNextRoomLocation(int);
  bool getRoomState();
  bool getCookRaiseState();
  bool getFactoryRaiseState();
  bool getFrontRaiseState();
  string getRoomName();
  void setNeighbors(Room*,Room*,Room*,Room*);
  virtual ~Room();
};

#endif
