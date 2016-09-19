/*************************************************
 * Program Filename: MagnifyingGlass.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The MagnifyingGlass class header file.
 * **********************************************/


#ifndef MAGNIFYINGGLASS_HPP
#define MAGNIFYINGGLASS_HPP
#include "Item.hpp"


class MagnifyingGlass : public Item
{
public:
  MagnifyingGlass(int);
  virtual void viewItem();
  virtual ~MagnifyingGlass();
};

#endif
