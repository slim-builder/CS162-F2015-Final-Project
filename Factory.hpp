/*************************************************
 * Program Filename: Factory.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Factory class header file.
 * **********************************************/


#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Room.hpp"

class Factory : public Room
{
private:
  bool machineState;
  bool factoryState;
public:
  Factory(int);
  virtual void special(int, Container*, int*);
  virtual void printActionList();
  virtual ~Factory();
};

#endif
