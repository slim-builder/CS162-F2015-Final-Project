/*************************************************
 * Program Filename: Container.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Container class definition file.
 * **********************************************/


#include "Container.hpp"
#include <iostream>
using std::cout;
using std::endl;
const int Container::toolbox;
const int Container::recyclebin;
const int Container::briefcase;
const int Container::mailbox;


/*****************************************************
 * Function: Container::Container(int)
 * Description: Container constructor
 * Parameters: Integer to represent the container type
 * of the Container
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Container::Container(int t) : type(t)
{
}


/*****************************************************
 * Function: Container::viewContents()
 * Description: Prints out the name and/or description
 * of each of the items currently in the container
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Container::viewContents()
{
  int i;
  vector<Item*>::iterator iter;
  cout << "Container Contents:" << endl;
  if (container.size() > 0)
  {
    for (iter = container.begin(), i = 1;
         iter != container.end();
         iter++, i++)
    {
      cout << i << ". ";
      (*iter)->viewItem();
    }
  }
  else
  {
    cout << "The container is empty." << endl;

  }
}


/*****************************************************
 * Function: Container::useItem(unsigned int)
 * Description: Returns the Item pointer of an Item
 * inside the container. The index indicates which
 * Item that the player is interested in.
 * Parameters: The player selection
 * Pre-Conditions: Valid integer
 * Post-Conditions: Item pointer may be null or non-
 * null.
*****************************************************/
Item* Container::useItem(unsigned int index)
{
  if (container.size() > 0 && index >= 1 && index <= container.size())
    return container[index-1];
  else
    return NULL;
}


/*****************************************************
 * Function: Container::removeItem(Item*)
 * Description: Removes the specified item from the
 * container.
 * Parameters: The Item pointer of the item to be removed
 * Pre-Conditions: Valid non-null Item pointer
 * Post-Conditions: None
*****************************************************/
void Container::removeItem(Item* item)
{
  for (vector<Item*>::iterator iter = container.begin();
       iter != container.end();
       iter++)
  {
    if (*iter == item)
    {
      container.erase(iter);
      break;
    }
  }
}


int Container::getType()
{
  return type;
}


/*****************************************************
 * Function: Container::~Container()
 * Description: Container destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Container::~Container()
{
  for (vector<Item*>::iterator iter = container.begin();
       iter != container.end();
       iter++)
  {
    delete (*iter);
  }
  container.clear();
}

