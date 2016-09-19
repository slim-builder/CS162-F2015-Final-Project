/*************************************************
 * Program Filename: KnifeFork.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The KnifeFork class header file.
 * **********************************************/


#ifndef KNIFEFORK_HPP
#define KNIFEFORK_HPP
#include "Item.hpp"


class KnifeFork : public Item
{
public:
  KnifeFork(int);
  virtual void viewItem();
  virtual ~KnifeFork();
};

#endif
