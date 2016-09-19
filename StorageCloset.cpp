/*************************************************
 * Program Filename: StorageCloset.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The StorageCloset class definition file.
 * **********************************************/


#include "StorageCloset.hpp"
#include "Toolbox.hpp"


/*****************************************************
 * Function: StorageCloset::StorageCloset(int,int)
 * Description: StorageCloset constructor
 * Parameters: The game difficulty level and the type
 * of Storage Closet room which determines the
 * type of Toolbox item container that is instantiated
 * in the Room
 * Pre-Conditions: Valid integers
 * Post-Conditions: None
*****************************************************/
StorageCloset::StorageCloset(int difficulty, int type) : Room()
{
  if (type == 1)
    name = "Storage Closet #1";
  else
    name = "Storage Closet #2";
  lightState = false;
  container = new Toolbox(type);
  roomState = true;
}


/*****************************************************
 * Function: StorageCloset::special(int,Container*,int*)
 * Description: Execute a player-selected action
 * localized to the StorageCloset room. 
 * Parameters: The type of action to execute, the
 * player's briefcase, and the player's remaining
 * budget.
 * Pre-Conditions: Valid integers and Container pointer
 * Post-Conditions: None
*****************************************************/
void StorageCloset::special(int actionId, Container *briefcase, int *budget)
{
  int item;
  if (actionId == 1)
  {
    lightState = true;
    cout << "The closet lights up!" << endl;
  }
  else if (actionId == 2)
  {
    if (!lightState)
      cout << "The closet is too dark!  You cannot open the Toolbox!" << endl;
    else
    {
      briefcase->viewContents();
      cout << "From your briefcase, please select an item" << endl;
      cout << "to put into the Toolbox by entering a number (enter zero to cancel): ";
      if (cin >> item)
        container->transferItem(briefcase->useItem(item), briefcase);
      else
        cout << "Invalid item selection.  Cannot put item into Toolbox." << endl;
    }
  }
  else if (actionId == 3)
  {
    if (!lightState)
      cout << "The closet is too dark!  You cannot open the Toolbox!" << endl;
    else
    {
      container->viewContents();
      cout << "From the Toolbox, please select an item" << endl;
      cout << "to put into the briefcase by entering a number (enter zero to cancel): ";
      if (cin >> item)
        briefcase->transferItem(container->useItem(item), container);
      else
        cout << "Invalid item selection.  Cannot put item into the briefcase." << endl;
    }
  }
}


void StorageCloset::printActionList()
{
  cout << "1. Turn on the light switch" << endl;
  cout << "2. Put item into the Toolbox" << endl;
  cout << "3. Take item from the Toolbox" << endl;
  cout << "Please select an action from the list above by entering a number: ";
}


StorageCloset::~StorageCloset()
{
}
