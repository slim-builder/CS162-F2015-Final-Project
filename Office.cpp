/*************************************************
 * Program Filename: Office.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Office class definition file.
 * **********************************************/


#include "Office.hpp"
#include "RecycleBin.hpp"
#include "CookDocument.hpp"
#include "FactoryDocument.hpp"
#include "FrontDocument.hpp"


/*****************************************************
 * Function: Office::Office()
 * Description: Office constructor
 * Parameters: Difficulty level
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
Office::Office(int difficulty) : Room()
{
  name = "Office";
  container = new RecycleBin();
  roomState = true;
}


/*****************************************************
 * Function: Office::special(int,Container*,int*)
 * Description: Execute a player-selected action
 * localized to the Office room. 
 * Parameters: The type of action to execute, the
 * player's briefcase, and the player's remaining
 * budget.
 * Pre-Conditions: Valid integers and Container pointer
 * Post-Conditions: None
*****************************************************/
void Office::special(int actionId, Container *briefcase, int *budget)
{
  int item, action;
  if (actionId == 1)
  {
    cout << "Welcome to the Payroll Department!" << endl;
    cout << "1. Raise pay for cook employees" << endl;
    cout << "2. Raise pay for factory employees" << endl;
    cout << "3. Raise pay for front-line employees" << endl;
    cout << "Please select an option by entering a number: ";
    if (cin >> action && action >= 1 && action <= 3)
    {
      if (action == 1)
        briefcase->addItem(new CookDocument(Container::briefcase));
      else if (action == 2)
        briefcase->addItem(new FactoryDocument(Container::briefcase));
      else 
        briefcase->addItem(new FrontDocument(Container::briefcase));
    }
    else
      cout << "Invalid selection.  No action was taken." << endl;
  }
  else if (actionId == 2)
  {
    briefcase->viewContents();
    cout << "From your briefcase, please select an item" << endl;
    cout << "to put into the Recycle Bin by entering a number (enter zero to cancel): ";
    if (cin >> item)
      container->transferItem(briefcase->useItem(item), briefcase);
    else
      cout << "Invalid item selection.  Cannot put item into Recycle Bin." << endl;
  }
  else if (actionId == 3)
  {
    container->viewContents();
    cout << "From the Recycle Bin, please select an item" << endl;
    cout << "to put into the briefcase by entering a number (enter zero to cancel): ";
    if (cin >> item)
      briefcase->transferItem(container->useItem(item), container);
    else
      cout << "Invalid item selection.  Cannot put item into the briefcase." << endl;
  }
}


/*****************************************************
 * Function: Office::printActionList()
 * Description: Prints out the list of possible
 * actions to execute while the player is in the
 * Office room.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Office::printActionList()
{
  cout << "1. Visit the Payroll Department" << endl;
  cout << "2. Put item into the Recycle Bin" << endl;
  cout << "3. Take item from the Recycle Bin" << endl;
  cout << "Please select an action from the list above by entering a number: ";
}


/*****************************************************
 * Function: Office::~Office()
 * Description: Office destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Office::~Office()
{
}
