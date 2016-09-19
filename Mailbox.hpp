/*************************************************
 * Program Filename: Mailbox.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Mailbox class header file.
 * **********************************************/


#ifndef MAILBOX_HPP
#define MAILBOX_HPP
#include "Container.hpp"

class Mailbox : public Container
{
public:
  Mailbox();
  virtual void transferItem(Item*,Container*);
  virtual void addItem(Item*);
  virtual ~Mailbox();
};

#endif
