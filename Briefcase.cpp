/*************************************************
 * Program Filename: Briefcase.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Briefcase class definition file.
 * **********************************************/


#include "Briefcase.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Briefcase::Briefcase()
 * Description: Briefcase constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Briefcase::Briefcase() : Container(Container::briefcase)
{
}


/*****************************************************
 * Function: Briefcase::transferItem(Item*,Container*)
 * Description: Transfer an item from another container
 * into the Container. The Briefcase only accepts an
 * item if there is free "slot" in the briefcase.
 * There are only four slots in the briefcase.
 * Parameters: Pointers to the item to be transferred
 * and the container that will "give up" the item.  The
 * Container receives the item.
 * Pre-Conditions: Item pointer may be null or non-null.
 * Container pointer must be non-null.
 * Post-Conditions: None
*****************************************************/
void Briefcase::transferItem(Item* item, Container* con)
{
  if (item)
  {
    if (container.size() < 4)
    {
      container.push_back(item);
      item->setContainerType(Container::briefcase);
      con->removeItem(item);
    }
    else
      cout << "Cannot add item to briefcase.  The briefcase is full." << endl;
  }
  else
    cout << "Cannot add invalid item to briefcase." << endl;
}


/*****************************************************
 * Function: Briefcase::addItem(Item*)
 * Description: Add the specified item to the Container.
 * This method differs from the transferItem method
 * in that the Item does not originate from another
 * container.  This method is used to "spawn" items out
 * of nowhere. The briefcase still enforces a four-
 * item limit on its contents.
 * Parameters: An item
 * Pre-Conditions: Valid Item pointer may be hull or
 * non-null.
 * Post-Conditions: None
*****************************************************/
void Briefcase::addItem(Item* item)
{
  if (item)
  {
    if (container.size() < 4)
      container.push_back(item);
    else
      cout << "Cannot add item to briefcase.  The briefcase is full." << endl;
  }
  else
    cout << "Cannot add invalid item to briefcase." << endl;
}


/*****************************************************
 * Function: Briefcase::~Briefcase()
 * Description: Briefcase destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Briefcase::~Briefcase()
{
}

