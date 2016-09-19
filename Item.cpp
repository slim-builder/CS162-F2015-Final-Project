/*************************************************
 * Program Filename: Item.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Item class definition file.
 * **********************************************/


#include "Item.hpp"
#include <iostream>
using std::cout;
using std::endl;
const int Item::screwdriver;
const int Item::wrench;
const int Item::hammer;
const int Item::magGlass;
const int Item::knifefork;
const int Item::comment1;
const int Item::comment2;
const int Item::comment3;
const int Item::cook;
const int Item::factory;
const int Item::front;


/*****************************************************
 * Function: Item::Item(int,int)
 * Description: Item constructor
 * Parameters: Integers to represent Item type and
 * the Container type of the container that the Item
 * is inside of.
 * Pre-Conditions: Valid integers
 * Post-Conditions: None
*****************************************************/
Item::Item(int t, int ct) : type(t), containerType(ct)
{
}


int Item::getType()
{
  return type;
}


void Item::setContainerType(int ct)
{
  containerType = ct;
}


int Item::getContainerType()
{
  return containerType;
}


/*****************************************************
 * Function: Item::~Item()
 * Description: Item destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Item::~Item()
{
}

