/*************************************************
 * Program Filename: Restaurant.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Restaurant class definition file.
 * **********************************************/


#include "Restaurant.hpp"


/*****************************************************
 * Function: Restaurant::Restaurant()
 * Description: Restaurant constructor
 * Parameters: Difficulty level
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Restaurant::Restaurant(int difficulty) : Room()
{
  cookState = true;
  frontState = true;
  ovenState = false;
  diningAreaState = false;
  name = "Restaurant";
  if (difficulty > 0)
    cookState = false;
  if (difficulty > 1)
    frontState = false;
}


/*****************************************************
 * Function: Restaurant::special(int,Container*,int*)
 * Description: Execute a player-selected action
 * localized to the Restaurant room. 
 * Parameters: The type of action to execute, the
 * player's briefcase, and the player's remaining
 * budget.
 * Pre-Conditions: Valid integers and Container pointer
 * Post-Conditions: None
*****************************************************/
void Restaurant::special(int actionId, Container *briefcase, int *budget)
{
  int item;
  Item *itemPtr;
  if (actionId == 1)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to review the restaurant pizza: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::knifefork)
      {
        if (cookState && ovenState)
          cout << "The pizza has a wonderful crispy crust!" << endl;
        else 
          cout << "The pizza has a chewy, soggy crust!  It doesn't taste good." << endl;
      }
      else
        cout << "Cannot review the pizza.  The selected item is incorrect." << endl;
    }
    else
      cout << "Cannot review the pizza.  The selected item is incorrect." << endl;
  }
  else if (actionId == 2)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to upgrade the pizza oven: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::screwdriver)
      {
        ovenState = true;
        cout << "The oven is upgraded!" << endl;
        roomState = cookState && frontState && ovenState && diningAreaState;
      }
      else
        cout << "Cannot upgrade the oven.  The selected item is incorrect." << endl;
    }
    else
      cout << "Cannot upgrade the oven.  The selected item is incorrect." << endl;
  }
  else if (actionId == 3)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to upgrade the dining area: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::hammer)
      {
	diningAreaState = true;
	cout << "The dining area is upgraded!" << endl;
        roomState = cookState && frontState && ovenState && diningAreaState;
      }
      else
	cout << "Cannot upgrade the dining area.  The selected item is incorrect." << endl;
    }
    else
      cout << "Cannot upgrade the dining area.  The selected item is incorrect." << endl;
  }
  else if (actionId == 4)
  {
    cout << "Chat with the restaurant patrons..." << endl;
    if (!diningAreaState)
      cout << "The dining area decor looks terrible!" << endl;
    else if (!frontState)
      cout << "The service is terrible!" << endl;
    else if (!cookState || !ovenState)
      cout << "The pizza is terrible!  Please review the pizza!" << endl;
    else
      cout << "The restaurant is wonderful!  We'll definitely visit again!" << endl;
  }
  else if (actionId == 5)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to notify cook employees of a pay raise: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::cook)
      {
        cookState = true;
        payRaiseState[0] = true;
        cout << "You present the cook pay raise document..." << endl;
        cout << "The cook employees are pleased!" << endl;
        roomState = cookState && frontState && ovenState && diningAreaState;
      }
      else
        cout << "There is nothing to present to the cook employees.  The selected item is incorrect." << endl;
    }
    else
      cout << "There is nothing to present to the cook employees.  The selected item is incorrect." << endl; 
  }
  else if (actionId == 6)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to notify front-line employees of a pay raise: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::front)
      {
        frontState = true;
        payRaiseState[2] = true;
        cout << "You present the front-line pay raise document..." << endl;
        cout << "The front-line employees are pleased!" << endl;
        roomState = cookState && frontState && ovenState && diningAreaState;
      }
      else
        cout << "There is nothing to present to the front-line employees.  The selected item is incorrect." << endl;
    }
    else
      cout << "There is nothing to present to the front-line employees.  The selected item is incorrect." << endl; 
  }
}


/*****************************************************
 * Function: Restaurant::printActionList()
 * Description: Prints out the list of possible
 * actions to execute while the player is in the
 * Restaurant room.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Restaurant::printActionList()
{
  cout << "1. Review the restaurant pizza" << endl;
  cout << "2. Upgrade the pizza oven" << endl;
  cout << "3. Upgrade the dining area" << endl;
  cout << "4. Chat with the restaurant patrons" << endl;
  cout << "5. Meet with the cook employees" << endl;
  cout << "6. Meet with the front-line employees" << endl;
  cout << "Please select an action from the list above by entering a number: ";
}


/*****************************************************
 * Function: Restaurant::~Restaurant()
 * Description: Restaurant destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Restaurant::~Restaurant()
{
}
