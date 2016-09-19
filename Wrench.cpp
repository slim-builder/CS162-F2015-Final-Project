/*************************************************
 * Program Filename: Wrench.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Wrench class definition file.
 * **********************************************/


#include "Wrench.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Wrench::Wrench(int)
 * Description: Wrench constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Wrench::Wrench(int ct) : Item(Item::wrench, ct)
{
}


/*****************************************************
 * Function: Wrench::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Wrench::viewItem()
{
  cout << "Wrench" << endl;
}


/*****************************************************
 * Function: Wrench::~Wrench()
 * Description: Wrench destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Wrench::~Wrench()
{
}

