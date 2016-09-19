/*************************************************
 * Program Filename: Office.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Office class header file.
 * **********************************************/


#ifndef OFFICE_HPP
#define OFFICE_HPP

#include "Room.hpp"

class Office : public Room
{
public:
  Office(int);
  virtual void special(int, Container*, int*);
  virtual void printActionList();
  virtual ~Office();
};

#endif
