/*************************************************
 * Program Filename: Room.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The Room class definition file.
 * **********************************************/


#include "Room.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: Room::Room()
 * Description: Room constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Room::Room() :
container(NULL),roomState(false)
{
  payRaiseState[0] = false;
  payRaiseState[1] = false;
  payRaiseState[2] = false;
}


/*****************************************************
 * Function: Room::printNavigationList()
 * Description: Prints out the names of the rooms
 * which are neighbors of the Room so that the player
 * can choose which room neighbor to move to.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void Room::printNavigationList()
{
  if (north)
    cout << "1. " << north->getRoomName() << endl;
  if (south)
    cout << "2. " << south->getRoomName() << endl;
  if (east)
    cout << "3. " << east->getRoomName() << endl;
  if (west)
    cout << "4. " << west->getRoomName() << endl;
  cout << "Enter a number to select the room you want to move to: ";
}


/*****************************************************
 * Function: Room::getNextRoomLocation(int)
 * Description: Returns the Room pointer of the room
 * selected by the player can that the game can keep
 * track of the player's location.  The selected room
 * represents the next room destination of the player.
 * Parameters: A number representing the player's
 * room selection.
 * Pre-Conditions: Valid integer
 * Post-Conditions: The player-requested Room pointer
*****************************************************/
Room* Room::getNextRoomLocation(int room)
{
  if (room == 1)
    return north;
  else if (room == 2)
    return south;
  else if (room == 3)
    return east;
  else if (room == 4)
    return west;
  else
    return this;
}


bool Room::getRoomState()
{
  return roomState;
}


bool Room::getCookRaiseState()
{
  return payRaiseState[0];
}


bool Room::getFactoryRaiseState()
{
  return payRaiseState[1];
}


bool Room::getFrontRaiseState()
{
  return payRaiseState[2];
}


string Room::getRoomName()
{
  return name;
}


/*****************************************************
 * Function: Room::setNeighbors(Room*,Room*,Room*,Room*)
 * Description: Sets the room neighbors of the Room
 * Parameters: The four Room neighbors of the Room
 * Pre-Conditions: The Room pointers may be null or
 * non-null
 * Post-Conditions: None
*****************************************************/
void Room::setNeighbors(Room *n, Room *s, Room *e, Room *w)
{
  north = n;
  south = s;
  east = e;
  west = w;
}


/*****************************************************
 * Function: Room::~Room()
 * Description: Room destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
Room::~Room()
{
  if (container)
    delete container;
}
