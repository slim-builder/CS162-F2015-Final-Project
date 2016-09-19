/*************************************************
 * Program Filename: CommentCard.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The CommentCard class header file.
 * **********************************************/


#ifndef COMMENTCARD_HPP
#define COMMENTCARD_HPP
#include "Item.hpp"


class CommentCard : public Item
{
public:
  CommentCard(int,int);
  virtual void viewItem();
  virtual ~CommentCard();
};

#endif
