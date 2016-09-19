/*************************************************
 * Program Filename: FactoryDocument.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The FactoryDocument class header file.
 * **********************************************/


#ifndef FACTORYDOCUMENT_HPP
#define FACTORYDOCUMENT_HPP
#include "Item.hpp"


class FactoryDocument : public Item
{
public:
  FactoryDocument(int);
  virtual void viewItem();
  virtual ~FactoryDocument();
};

#endif
