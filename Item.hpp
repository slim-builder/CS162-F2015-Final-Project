/*************************************************
 * Program Filename: Item.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Item class header file.
 * **********************************************/


#ifndef ITEM_HPP
#define ITEM_HPP

class Container;
class Item
{
public:
  static const int screwdriver = 1;
  static const int wrench = 2;
  static const int hammer = 3;
  static const int magGlass = 4;
  static const int knifefork = 5;
  static const int comment1 = 6;
  static const int comment2 = 7;
  static const int comment3 = 8;
  static const int cook = 9;
  static const int factory = 10;
  static const int front = 11;

protected:
  int type;
  int containerType;

public:
  Item(int,int);
  virtual void viewItem() = 0;
  int getType();
  void setContainerType(int);
  int getContainerType();
  virtual ~Item();
};


#endif
