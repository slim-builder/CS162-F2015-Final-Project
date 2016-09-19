/*************************************************
 * Program Filename: LoadingDock.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The LoadingDock class definition file.
 * **********************************************/


#include "LoadingDock.hpp"


/*****************************************************
 * Function: LoadingDock::LoadingDock(int)
 * Description: LoadingDock constructor
 * Parameters: Difficulty level
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
LoadingDock::LoadingDock(int difficulty) : Room()
{
  meatState = true;
  vegetableState = true;
  name = "Loading Dock";
  truckState = false;
  if (difficulty > 0)
    meatState = false;
  if (difficulty > 1)
    vegetableState = false;
}


/*****************************************************
 * Function: LoadingDock::special(int,Container*,int*)
 * Description: Execute a player-selected action
 * localized to the LoadingDock room. 
 * Parameters: The type of action to execute, the
 * player's briefcase, and the player's remaining
 * budget.
 * Pre-Conditions: Valid integers and Container pointer
 * Post-Conditions: None
*****************************************************/
void LoadingDock::special(int actionId, Container *briefcase, int *budget)
{
  int item, action;
  Item *itemPtr;
  if (actionId == 1)
  {
    cout << "Inspecting delivery trucks..." << endl;
    if (truckState)
      cout << "Delivery truck interior is freezing cold!" << endl;
    else
      cout << "Delivery truck interior feels surprisely warm!" << endl;
  }
  else if (actionId == 2)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select the required item ";
    cout << "to inspect ingredients: ";
    if (cin >> item)
    {
      itemPtr = briefcase->useItem(item);
      if (itemPtr && itemPtr->getType() == Item::magGlass)
      {
        if (meatState)
          cout << "The meat looks great!" << endl;
        else 
          cout << "The meat looks spoiled!" << endl;
        if (vegetableState)
          cout << "The vegetables look great!" << endl;
        else
          cout << "The vegetables look spoiled!" << endl;
      }
      else
        cout << "Cannot inspect ingredients.  The selected item is incorrect." << endl;
    }
    else
      cout << "Cannot inspect ingredients.  The selected item is incorrect." << endl;
  }
  else if (actionId == 3)
  {
    cout << "You are logged into the computer" << endl;
    cout << "1. Upgrade delivery trucks ($300)" << endl;
    cout << "2. Order new meat ingredients ($300)" << endl;
    cout << "3. Order new vegetable ingredients ($300)" << endl;
    cout << "Select an action by entering a number: ";
    if ((cin >> action) && action >= 1 && action <= 3)
    {
      if (action == 1)
      {
        truckState = true;
        *budget -= 300;
      }
      else if (action == 2)
      {
        meatState = true;
        *budget -= 300;
      }
      else
      {
        vegetableState = true;
        *budget -= 300;
      }
      roomState = truckState && meatState && vegetableState;
    }
    else
      cout << "Invalid selection.  No action was taken." << endl;
  }
}


/*****************************************************
 * Function: LoadingDock::printActionList()
 * Description: Prints out the list of possible
 * actions to execute while the player is in the
 * LoadingDock room.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void LoadingDock::printActionList()
{
  cout << "1. Inspect delivery trucks" << endl;
  cout << "2. Inspect ingredients" << endl;
  cout << "3. Use computer" << endl;
  cout << "Please select an action from the list above by entering a number: ";
}


/*****************************************************
 * Function: LoadingDock::~LoadingDock()
 * Description: LoadingDock destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
LoadingDock::~LoadingDock()
{
}
