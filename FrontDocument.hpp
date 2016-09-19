/*************************************************
 * Program Filename: FrontDocument.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The FrontDocument class header file.
 * **********************************************/


#ifndef FRONTDOCUMENT_HPP
#define FRONTDOCUMENT_HPP
#include "Item.hpp"


class FrontDocument : public Item
{
public:
  FrontDocument(int);
  virtual void viewItem();
  virtual ~FrontDocument();
};

#endif
