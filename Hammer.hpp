/*************************************************
 * Program Filename: Hammer.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Hammer class header file.
 * **********************************************/


#ifndef HAMMER_HPP
#define HAMMER_HPP
#include "Item.hpp"


class Hammer : public Item
{
public:
  Hammer(int);
  virtual void viewItem();
  virtual ~Hammer();
};

#endif
