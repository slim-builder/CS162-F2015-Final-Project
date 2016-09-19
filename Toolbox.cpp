/*************************************************
 * Program Filename: Toolbox.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Toolbox class definition file.
 * **********************************************/


#include "Toolbox.hpp"
#include "Screwdriver.hpp"
#include "Wrench.hpp"
#include "Hammer.hpp"
#include "MagnifyingGlass.hpp"
#include "KnifeFork.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Toolbox::Toolbox(int)
 * Description: Toolbox constructor
 * Parameters: Integer to represent the type
 * of Toolbox.  The type of Toolbox determines what
 * items are instantiated inside the Toolbox at the
 * time that the Toolbox is instantiated.
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Toolbox::Toolbox(int initType) : Container(Container::toolbox)
{
  if (initType == 1)
  {
    addItem(new KnifeFork(Container::toolbox));
    addItem(new Wrench(Container::toolbox));
  }
  else
  {
    addItem(new Hammer(Container::toolbox));
    addItem(new MagnifyingGlass(Container::toolbox));
    addItem(new Screwdriver(Container::toolbox));
  }
}


/*****************************************************
 * Function: Toolbox::transferItem(Item*,Container*)
 * Description: Transfer an item from another container
 * into the Container.  The Toolbox only accepts tool
 * items.
 * Parameters: Pointers to the item to be transferred
 * and the container that will "give up" the item.  The
 * Container receives the item.
 * Pre-Conditions: Item pointer may be null or non-null.
 * Container pointer must be non-null.
 * Post-Conditions: None
*****************************************************/
void Toolbox::transferItem(Item* item, Container* con)
{
  if (item && item->getType() >= Item::screwdriver &&
      item->getType() <= Item::knifefork)
  {
    container.push_back(item);
    item->setContainerType(Container::toolbox);
    con->removeItem(item);
  }
  else
    cout << "Cannot add non-tool or invalid item to the Toolbox" << endl;
}


/*****************************************************
 * Function: Toolbox::addItem(Item*)
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
void Toolbox::addItem(Item* item)
{
  if (item)
    container.push_back(item);
}


/*****************************************************
 * Function: Toolbox::~Toolbox()
 * Description: Toolbox destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Toolbox::~Toolbox()
{
}

