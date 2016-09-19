/*************************************************
 * Program Filename: Briefcase.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Briefcase class header file.
 * **********************************************/


#ifndef BRIEFCASE_HPP
#define BRIEFCASE_HPP
#include "Container.hpp"

class Briefcase : public Container
{
public:
  Briefcase();
  virtual void transferItem(Item*,Container*);
  virtual void addItem(Item*);
  virtual ~Briefcase();
};

#endif
