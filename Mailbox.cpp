/*************************************************
 * Program Filename: Mailbox.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Mailbox class definition file.
 * **********************************************/


#include "Mailbox.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Mailbox::Mailbox()
 * Description: Mailbox constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Mailbox::Mailbox() : Container(Container::mailbox)
{
}


/*****************************************************
 * Function: Mailbox::transferItem(Item*,Container*)
 * Description: Transfer an item from another container
 * into the Container.
 * Parameters: Pointers to the item to be transferred
 * and the container that will "give up" the item.  The
 * Container receives the item.
 * Pre-Conditions: Item pointer may be null or non-null.
 * Container pointer must be non-null.
 * Post-Conditions: None
*****************************************************/
void Mailbox::transferItem(Item* item, Container* con)
{
}


/*****************************************************
 * Function: Mailbox::addItem(Item*)
 * Description: Add the specified item to the Container.
 * This method differs from the transferItem method
 * in that the Item does not originate from another
 * container.  This method is used to "spawn" items out
 * of nowhere.
 * Parameters: An item
 * Pre-Conditions: Valid Item pointer may be hull or
 * non-null.
 * Post-Conditions: None
*****************************************************/
void Mailbox::addItem(Item* item)
{
  if (item)
  {
    container.clear();
    container.push_back(item);
  }
}


/*****************************************************
 * Function: Mailbox::~Mailbox()
 * Description: Mailbox destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Mailbox::~Mailbox()
{
}

