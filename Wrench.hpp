/*************************************************
 * Program Filename: Wrench.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Wrench class header file.
 * **********************************************/


#ifndef WRENCH_HPP
#define WRENCH_HPP
#include "Item.hpp"


class Wrench : public Item
{
public:
  Wrench(int);
  virtual void viewItem();
  virtual ~Wrench();
};

#endif
