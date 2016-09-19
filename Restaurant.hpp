/*************************************************
 * Program Filename: Restaurant.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Restaurant class header file.
 * **********************************************/


#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "Room.hpp"

class Restaurant : public Room
{
private:
  bool cookState;
  bool frontState;
  bool ovenState;
  bool diningAreaState;
public:
  Restaurant(int);
  virtual void special(int, Container*, int*);
  virtual void printActionList();
  virtual ~Restaurant();
};

#endif
