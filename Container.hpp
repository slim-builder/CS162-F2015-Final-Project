/*************************************************
 * Program Filename: Container.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Container class header file.
 * **********************************************/


#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <vector>
#include "Item.hpp"
using std::vector;


class Container
{
public:
  static const int toolbox = 1;
  static const int recyclebin = 2;
  static const int briefcase = 3;
  static const int mailbox = 4;

protected:
  vector<Item*> container;
  int type;

public:
  Container(int);
  void viewContents();
  virtual void transferItem(Item*,Container*) = 0;
  virtual void addItem(Item*) = 0;
  Item* useItem(unsigned int);
  void removeItem(Item*);
  int getType();
  virtual ~Container();
};


#endif
