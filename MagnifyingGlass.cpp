/*************************************************
 * Program Filename: MagnifyingGlass.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The MagnifyingGlass class definition file.
 * **********************************************/


#include "MagnifyingGlass.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: MagnifyingGlass::MagnifyingGlass(int)
 * Description: MagnifyingGlass constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
MagnifyingGlass::MagnifyingGlass(int ct) : Item(Item::magGlass, ct)
{
}


/*****************************************************
 * Function: MagnifyingGlass::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void MagnifyingGlass::viewItem()
{
  cout << "Magnifying Glass" << endl;
}


/*****************************************************
 * Function: MagnifyingGlass::~MagnifyingGlass()
 * Description: MagnifyingGlass destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
MagnifyingGlass::~MagnifyingGlass()
{
}

