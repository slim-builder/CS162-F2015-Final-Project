/*************************************************
 * Program Filename: Toolbox.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Toolbox class header file.
 * **********************************************/


#ifndef TOOLBOX_HPP
#define TOOLBOX_HPP
#include "Container.hpp"

class Toolbox : public Container
{
public:
  Toolbox(int);
  virtual void transferItem(Item*,Container*);
  virtual void addItem(Item*);
  virtual ~Toolbox();
};

#endif
