/*************************************************
 * Program Filename: Hammer.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Hammer class definition file.
 * **********************************************/


#include "Hammer.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Hammer::Hammer(int)
 * Description: Hammer constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Hammer::Hammer(int ct) : Item(Item::hammer, ct)
{
}


/*****************************************************
 * Function: Hammer::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Hammer::viewItem()
{
  cout << "Hammer" << endl;
}


/*****************************************************
 * Function: Hammer::~Hammer()
 * Description: Hammer destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Hammer::~Hammer()
{
}

