/*************************************************
 * Program Filename: CookDocument.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The CookDocument class definition file.
 * **********************************************/


#include "CookDocument.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: CookDocument::CookDocument(int)
 * Description: CookDocument constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
CookDocument::CookDocument(int ct) : Item(Item::cook, ct)
{
}


/*****************************************************
 * Function: CookDocument::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void CookDocument::viewItem()
{
  cout << "Cook Document" << endl;
}


/*****************************************************
 * Function: CookDocument::~CookDocument()
 * Description: CookDocument destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
CookDocument::~CookDocument()
{
}

