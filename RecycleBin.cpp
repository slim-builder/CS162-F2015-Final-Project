/*************************************************
 * Program Filename: RecycleBin.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The RecycleBin class definition file.
 * **********************************************/


#include "RecycleBin.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: RecycleBin::RecycleBin()
 * Description: RecycleBin constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
RecycleBin::RecycleBin() : Container(Container::recyclebin)
{
}


/*****************************************************
 * Function: RecycleBin::transferItem(Item*,Container*)
 * Description: Transfer an item from another container
 * into the Container. The RecycleBin only accepts
 * paper items.
 * Parameters: Pointers to the item to be transferred
 * and the container that will "give up" the item.  The
 * Container receives the item.
 * Pre-Conditions: Item pointer may be null or non-null.
 * Container pointer must be non-null.
 * Post-Conditions: None
*****************************************************/
void RecycleBin::transferItem(Item* item, Container* con)
{
  if (item)
  {
    if (item->getType() >= Item::comment1 &&
        item->getType() <= Item::front)
    {
      container.push_back(item);
      item->setContainerType(Container::recyclebin);
      con->removeItem(item);
    }
    else
      cout << "Cannot add non-paper item to the Recycle Bin" << endl;
  }
  else
    cout << "Cannot add invalid item to the Recycle Bin" << endl;
}


/*****************************************************
 * Function: RecycleBin::addItem(Item*)
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
void RecycleBin::addItem(Item* item)
{
}


/*****************************************************
 * Function: RecycleBin::~RecycleBin()
 * Description: RecycleBin destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
RecycleBin::~RecycleBin()
{
}

