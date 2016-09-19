/*************************************************
 * Program Filename: RecycleBin.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The RecycleBin class header file.
 * **********************************************/


#ifndef RECYCLEBIN_HPP
#define RECYCLEBIN_HPP
#include "Container.hpp"

class RecycleBin : public Container
{
public:
  RecycleBin();
  virtual void transferItem(Item*,Container*);
  virtual void addItem(Item*);
  virtual ~RecycleBin();
};

#endif
