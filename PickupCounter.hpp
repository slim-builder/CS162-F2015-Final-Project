/*************************************************
 * Program Filename: PickupCounter.hpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The PickupCounter class header file.
 * **********************************************/


#ifndef PICKUPCOUNTER_HPP
#define PICKUPCOUNTER_HPP

#include "Room.hpp"

class PickupCounter : public Room
{
private:
  bool salesPromoState;
  bool loyaltyPromoState;
public:
  PickupCounter(int);
  virtual void special(int, Container*, int*);
  virtual void printActionList();
  virtual ~PickupCounter();
};

#endif
