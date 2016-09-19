/*************************************************
 * Program Filename: Factory.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Factory class definition file.
 * **********************************************/


#include "Factory.hpp"


/*****************************************************
 * Function: Factory::Factory()
 * Description: Factory constructor
 * Parameters: Difficulty level
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Factory::Factory(int difficulty) : Room()
{
  factoryState = true;
  name = "Factory";
  machineState = false;
  if (difficulty > 1)
    factoryState = false;
}


/*****************************************************
 * Function: Factory::special(int,Container*,int*)
 * Description: Execute a player-selected action
 * localized to the Factory room. 
 * Parameters: The type of action to execute, the
 * player's briefcase, and the player's remaining
 * budget.
 * Pre-Conditions: Valid integers and Container pointer
 * Post-Conditions: None
*****************************************************/
void Factory::special(int actionId, Container *briefcase, int *budget)
{
  int item;
  Item *itemPtr;
  if (actionId == 1)
  {
    cout << "Reading customer feedback from retailers..." << endl;
    if (machineState)
      cout << "Delivery of frozen pizza is always on time." << endl;
    else
      cout << "The frozen pizza shipment sizes are lower than normal." << endl;
    if (factoryState && west->getRoomState())
      cout << "Our shoppers love the frozen pizzas." << endl;
    else
      cout << "Our shoppers have noticed a decrease in pizza quality." << endl;
  }
  else if (actionId == 2)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to upgrade the machines: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::wrench)
      {
        machineState = true;
        cout << "The machines have been upgraded!  You are skilled with the wrench!" << endl;
        roomState = machineState && factoryState;
      }
      else
        cout << "Cannot upgrade machines.  The selected item is incorrect." << endl;
    }
    else
      cout << "Cannot upgrade machines.  The selected item is incorrect." << endl;
  }
  else if (actionId == 3)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to notify factory employees of a pay raise: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::factory)
      {
        factoryState = true;
        payRaiseState[1] = true;
        cout << "You present the factory pay raise document..." << endl;
        cout << "The factory employees are pleased!" << endl;
        roomState = machineState && factoryState;
      }
      else
        cout << "There is nothing to present to the factory employees.  The selected item is incorrect." << endl;
    }
    else
      cout << "There is nothing to present to the factory employees.  The selected item is incorrect." << endl;
  }
}


/*****************************************************
 * Function: Factory::printActionList()
 * Description: Prints out the list of possible
 * actions to execute while the player is in the
 * Factory room.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Factory::printActionList()
{
  cout << "1. Read customer feedback from frozen pizza retailers" << endl;
  cout << "2. Upgrade flash freezer machines" << endl;
  cout << "3. Meet with factory employees" << endl;
  cout << "Please select an action from the list above by entering a number: ";
}


/*****************************************************
 * Function: Factory::~Factory()
 * Description: Factory destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Factory::~Factory()
{
}
