/*************************************************
 * Program Filename: CookDocument.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The CookDocument class header file.
 * **********************************************/


#ifndef COOKDOCUMENT_HPP
#define COOKDOCUMENT_HPP
#include "Item.hpp"


class CookDocument : public Item
{
public:
  CookDocument(int);
  virtual void viewItem();
  virtual ~CookDocument();
};

#endif
