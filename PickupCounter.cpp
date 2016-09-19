/*************************************************
 * Program Filename: PickupCounter.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The PickupCounter class definition file.
 * **********************************************/


#include "PickupCounter.hpp"
#include "Mailbox.hpp"
#include "CommentCard.hpp"


/*****************************************************
 * Function: PickupCounter::PickupCounter()
 * Description: PickupCounter constructor
 * Parameters: Difficulty level
 * Pre-Conditions: Valid integer
 * Post-Conditions: None
*****************************************************/
PickupCounter::PickupCounter(int difficulty) : Room()
{
  salesPromoState = false;
  loyaltyPromoState = true;
  if (difficulty > 1)
    loyaltyPromoState = false;
  name = "Pickup Counter";
  container = new Mailbox();
  container->addItem(new CommentCard(Item::comment1,Container::mailbox));
}


/*****************************************************
 * Function: PickupCounter::special(int,Container*,int*)
 * Description: Execute a player-selected action
 * localized to the PickupCounter room. 
 * Parameters: The type of action to execute, the
 * player's briefcase, and the player's remaining
 * budget.
 * Pre-Conditions: Valid integers and Container pointer
 * Post-Conditions: None
*****************************************************/
void PickupCounter::special(int actionId, Container *briefcase, int *budget)
{
  int action;
  Item *itemPtr;
  if (actionId == 1)
  {
    cout << "Attempt to pick up a comment card from the Mailbox..." << endl;
    itemPtr = container->useItem(1);
    if (itemPtr)
    {
      cout << "There's a comment card in the Mailbox!" << endl;
      briefcase->transferItem(itemPtr, container);
    }
    else
      cout << "The Mailbox is empty!" << endl;
  }
  else if (actionId == 2)
  {
    cout << "You are logged into the computer" << endl;
    cout << "1. Implement the free soda with pizza purchase sales promotion ($300)" << endl;
    cout << "2. Implement the buy five pizzas, get one free sales promotion ($300)" << endl;
    cout << "Please select an action from the list above by entering a number: ";
    if ((cin >> action) && action >= 1 && action <= 2)
    {
      if (action == 1)
      {
        if (!salesPromoState && !loyaltyPromoState)
          container->addItem(new CommentCard(Item::comment2,Container::mailbox));
        else if (!salesPromoState && loyaltyPromoState)
          container->addItem(new CommentCard(Item::comment3,Container::mailbox));
        salesPromoState = true;
        *budget -= 300;
      }
      else
      {
        if (salesPromoState && !loyaltyPromoState)
          container->addItem(new CommentCard(Item::comment3,Container::mailbox));
        loyaltyPromoState = true;
        *budget -= 300;
      }
      roomState = salesPromoState && loyaltyPromoState;
    }
    else
      cout << "Invalid selection.  No action was taken." << endl;
  }
}


/*****************************************************
 * Function: PickupCounter::printActionList()
 * Description: Prints out the list of possible
 * actions to execute while the player is in the
 * PickupCounter room.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void PickupCounter::printActionList()
{
  cout << "1. Take item from the Mailbox" << endl;
  cout << "2. Use the computer to implement a new sales promotion" << endl;
  cout << "Please select an action from the list above by entering a number: ";
}


/*****************************************************
 * Function: PickupCounter::~PickupCounter()
 * Description: PickupCounter destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
PickupCounter::~PickupCounter()
{
}
