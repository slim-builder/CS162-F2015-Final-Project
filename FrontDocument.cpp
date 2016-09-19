/*************************************************
 * Program Filename: FrontDocument.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The FrontDocument class definition file.
 * **********************************************/


#include "FrontDocument.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: FrontDocument::FrontDocument(int)
 * Description: FrontDocument constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
FrontDocument::FrontDocument(int ct) : Item(Item::front, ct)
{
}


/*****************************************************
 * Function: FrontDocument::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void FrontDocument::viewItem()
{
  cout << "Front-line Document" << endl;
}


/*****************************************************
 * Function: FrontDocument::~FrontDocument()
 * Description: FrontDocument destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
FrontDocument::~FrontDocument()
{
}

