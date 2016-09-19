/*************************************************
 * Program Filename: FactoryDocument.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The FactoryDocument class definition file.
 * **********************************************/


#include "FactoryDocument.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: FactoryDocument::FactoryDocument(int)
 * Description: FactoryDocument constructor
 * Parameters: Integer to represent the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
FactoryDocument::FactoryDocument(int ct) : Item(Item::factory, ct)
{
}


/*****************************************************
 * Function: FactoryDocument::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void FactoryDocument::viewItem()
{
  cout << "Factory Document" << endl;
}


/*****************************************************
 * Function: FactoryDocument::~FactoryDocument()
 * Description: FactoryDocument destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
FactoryDocument::~FactoryDocument()
{
}

