/*************************************************
 * Program Filename: KnifeFork.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The KnifeFork class definition file.
 * **********************************************/


#include "KnifeFork.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: KnifeFork::KnifeFork(int)
 * Description: KnifeFork constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
KnifeFork::KnifeFork(int ct) : Item(Item::knifefork, ct)
{
}


/*****************************************************
 * Function: KnifeFork::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void KnifeFork::viewItem()
{
  cout << "Knife & Fork" << endl;
}


/*****************************************************
 * Function: KnifeFork::~KnifeFork()
 * Description: KnifeFork destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
KnifeFork::~KnifeFork()
{
}

