/*************************************************
 * Program Filename: Screwdriver.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Screwdriver class definition file.
 * **********************************************/


#include "Screwdriver.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Screwdriver::Screwdriver(int)
 * Description: Screwdriver constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Screwdriver::Screwdriver(int ct) : Item(Item::screwdriver, ct)
{
}


/*****************************************************
 * Function: Screwdriver::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Screwdriver::viewItem()
{
  cout << "Screwdriver" << endl;
}


/*****************************************************
 * Function: Screwdriver::~Screwdriver()
 * Description: Screwdriver destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Screwdriver::~Screwdriver()
{
}

