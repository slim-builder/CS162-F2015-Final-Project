/*************************************************
 * Program Filename: game.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: This program implements a game
 * where the player acts as a pizza business
 * owner.  The player must move between different
 * rooms throughout her business building and
 * fix business operational issues which are
 * generating customer complaints.  The goal of
 * the game is to make the customers happy
 * within a limited budget. The player will find
 * and use items to achieve the goal.  The game
 * ends when the player either achieves the goal or
 * runs out of money in her budget. Time will
 * pass in the game such that the player's employees
 * will be paid some money out of the player's
 * budget for each game hour that passes.
 * **********************************************/
#include "game.hpp"
#include "Item.hpp"
#include "Container.hpp"
#include "Room.hpp"
#include "LoadingDock.hpp"
#include "Factory.hpp"
#include "StorageCloset.hpp"
#include "Office.hpp"
#include "Restaurant.hpp"
#include "PickupCounter.hpp"
#include "Screwdriver.hpp"
#include "Wrench.hpp"
#include "Hammer.hpp"
#include "MagnifyingGlass.hpp"
#include "KnifeFork.hpp"
#include "CommentCard.hpp"
#include "CookDocument.hpp"
#include "FactoryDocument.hpp"
#include "FrontDocument.hpp"
#include "Toolbox.hpp"
#include "RecycleBin.hpp"
#include "Briefcase.hpp"
#include "Mailbox.hpp"
// Set inital budget for the player
const int initialBudget = 6000;

int main()
{
  // Prompt user to select the level of difficulty for the game.
  cout << "Please select the game difficulty level (Default: Easy)" << endl;
  cout << "Enter 0 for Easy, 1 for Medium, or 2 for Hard: ";
  int difficulty;
  if (!(cin >> difficulty) || difficulty < 0 || difficulty > 2)
  {
    cin.clear();
    cin.ignore(1000, '\n');
    difficulty = 0;
  }
  cout << "Game Difficulty Level: ";
  if (difficulty == 0)
    cout << "Easy" << endl;
  else if (difficulty == 1)
    cout << "Medium" << endl;
  else
    cout << "Hard" << endl;
  // Prompt user to begin the game.  Otherwise, quit the program.
  cout << "Begin the game? (Default: n)" << endl;
  cout << "Enter y for yes, n for no: ";
  char begin;
  if (!(cin >> begin) || begin != 'y')
  {
    cin.clear();
    cin.ignore(1000, '\n');
    return 0;
  }
  // Initialize the game parameters such as the Room objects
  int budget = initialBudget, currGameClock = 0, prevGameClock = 0;
  int menuSelect, navSelect, actSelect;
  int payRates[3] = {100, 200, 50};
  bool customersHappy = false, payRaiseState[3] = {false, false, false};
  Room *building[7];
  building[0] = new LoadingDock(difficulty);
  building[1] = new Factory(difficulty);
  building[2] = new Office(difficulty);
  building[3] = new StorageCloset(difficulty, 1);
  building[4] = new StorageCloset(difficulty, 2);
  building[5] = new Restaurant(difficulty);
  building[6] = new PickupCounter(difficulty);
  building[0]->setNeighbors(NULL, NULL, building[1], NULL);
  building[1]->setNeighbors(NULL, building[5], building[2], building[0]);
  building[2]->setNeighbors(building[4], building[6], building[3], building[1]);
  building[3]->setNeighbors(NULL, NULL, NULL, building[2]);
  building[4]->setNeighbors(NULL, building[2], NULL, NULL);
  building[5]->setNeighbors(building[1], NULL, building[6], NULL);
  building[6]->setNeighbors(building[2], NULL, NULL, building[5]);
  // Player begins the game in the Office room
  Room *location = building[2], *temp;
  Container *briefcase = new Briefcase();
  // Game explanation to the player
  cout << endl << "Welcome to the Pizza Business Game!" << endl;
  cout << "You are the owner of a pizza business which runs" << endl;
  cout << "a pizza restaurant, a pizza takeout business," << endl;
  cout << "and a frozen pizza factory.  You have three distinct" << endl;
  cout << "groups of customers who are unhappy about some aspect" << endl;
  cout << "of your business. You must address all customer complaints" << endl;
  cout << "by moving around your business building and fixing problems.";
  cout << endl << endl;
  cout << "The Goal of the game is to satisfy all three" << endl;
  cout << "groups of customers before your starting budget runs out." << endl;
  cout << "Your customers require that every problem in every room" << endl;
  cout << "be resolved before they are satisfied." << endl;
  cout << "You will have a briefcase in which you may carry up to four items." << endl;
  cout << "The use of some items will be required to win the game.";
  cout << endl << endl;
  cout << "As you travel between the rooms of your business building," << endl;
  cout << "some time will pass and your employees will be paid out of" << endl;
  cout << "your budget. Fixing problems with your business may also" << endl;
  cout << "cost money and decrease your budget further." << endl;
  cout << "You lose the game if your budget is zero or less before" << endl;
  cout << "your customer groups can be satisfied." << endl << endl;
  // The game ends when the budget is zero or less or when all the
  // customers are happy.
  while (budget > 0 && !customersHappy)
  {
    // Up-to-date game information is displayed to the player
    cout << "The current game time: " << currGameClock << endl;
    cout << "Your current location: " << location->getRoomName() << endl;
    cout << "Your remaining budget: " << budget << endl;
    // Provide an action menu to the player.
    cout << "1. Move to another room" << endl;
    cout << "2. Execute an action at your current location" << endl;
    cout << "3. View briefcase contents" << endl;
    cout << "4. Reveal the goal of the game" << endl;
    cout << "Please select one of the above options by entering a number: ";
    while (!(cin >> menuSelect) || menuSelect < 1 || menuSelect > 4)
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid selection. Please enter another number: ";
    }
    if (menuSelect == 1)
    {
      location->printNavigationList();
      while(!(cin >> navSelect))
      {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid selection. Please enter another number: ";
      }
      // Get the location of the Room that the player wants to
      // move to.
      temp = location->getNextRoomLocation(navSelect);
      if (temp)
        location = temp;
      // Advance game clock after every transition from one room to
      // another.
      currGameClock++;
    }
    else if (menuSelect == 2)
    {
      location->printActionList();
      while(!(cin >> actSelect))
      {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid selection. Please enter another number: ";
      }
      // Execute an action inside the room based on the player's
      // action selection.
      location->special(actSelect, briefcase, &budget);
    }
    else if (menuSelect == 3)
    {
      // Display the contents of the player's briefcase
      cout << "Your briefcase contains:" << endl;
      briefcase->viewContents();
    }
    else
    {
      // Display the goal of the game to the player
      cout << "The goal of the game is to keep the frozen pizza" << endl;
      cout << "factory customers, the restaurant patrons, and the" << endl;
      cout << "takeout pizza customers happy by fixing various" << endl;
      cout << "problems with your business.  Each group has their own" << endl;
      cout << "issues with your business which you must address." << endl;
      cout << "Each room provides clues about the nature of those" << endl;
      cout << "customer issues which are local to the room." << endl;
    }
    // Determine the overall customer status and employee pay raise status
    // by aggregating the status information of every room together.
    customersHappy = building[0]->getRoomState();
    payRaiseState[0] = building[0]->getCookRaiseState();
    payRaiseState[1] = building[0]->getFactoryRaiseState();
    payRaiseState[2] = building[0]->getFrontRaiseState();
    for (int i = 1; i < 7; i++)
    {
      customersHappy = customersHappy && building[i]->getRoomState();
      payRaiseState[0] = payRaiseState[0] || building[i]->getCookRaiseState();
      payRaiseState[1] = payRaiseState[1] || building[i]->getFactoryRaiseState();
      payRaiseState[2] = payRaiseState[2] || building[i]->getFrontRaiseState();
    }
    // Check if the game clock actually advanced before notifying
    // the player that a game hour has passed and deducting hourly
    // employee pay from the player's budget. This is necessary
    // because viewing the briefcase contents or checking the goal of
    // the game should not cost any time or money.
    // The game clock must advance by two for a game hour to pass.
    if (currGameClock > 0 && currGameClock > prevGameClock
        && currGameClock % 2 == 0)
    {
      prevGameClock = currGameClock;
      cout << "An hour has passed" << endl;
      budget -= payRates[0] + payRates[1] + payRates[2];
    }
    // Implement employee pay raise
    if (payRaiseState[0])
      payRates[0] = 150;
    if (payRaiseState[1])
      payRates[1] = 300;
    if (payRaiseState[2])
      payRates[2] = 75;
  }
  // Check if the player won or lost the game.
  // Print the appropriate message to the player.
  if (customersHappy)
  {
    cout << "Congratulations, you won the game!" << endl;
    cout << "All of your customers are happy!" << endl;
  }
  else
  {
    cout << "Game over. Your budget was completely spent before all" << endl;
    cout << "the customer issues could be resolved." << endl;
    cout << "Sorry, you lost the game." << endl;
  }
  // De-allocate memory
  delete building[0];
  delete building[1];
  delete building[2];
  delete building[3];
  delete building[4];
  delete building[5];
  delete building[6];
  delete briefcase;
  return 0;
}
