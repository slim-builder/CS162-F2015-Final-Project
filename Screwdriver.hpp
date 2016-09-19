/*************************************************
 * Program Filename: Screwdriver.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Screwdriver class header file.
 * **********************************************/


#ifndef SCREWDRIVER_HPP
#define SCREWDRIVER_HPP
#include "Item.hpp"

class Screwdriver : public Item
{
public:
  Screwdriver(int);
  virtual void viewItem();
  virtual ~Screwdriver();
};

#endif
