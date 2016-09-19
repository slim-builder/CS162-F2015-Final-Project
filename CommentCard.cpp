/*************************************************
 * Program Filename: CommentCard.cpp
 * Author: Steven Lim
 * Date: 12/8/2015
 * Description: The CommentCard class definition file.
 * **********************************************/


#include "CommentCard.hpp"
#include "Container.hpp"
#include <iostream>
using std::cout;
using std::endl;


/*****************************************************
 * Function: CommentCard::CommentCard(int,int)
 * Description: CommentCard constructor
 * Parameters: Integers to represent the type of 
 * comment card item and the Container type
 * of the container that the Item is inside of.
 * Pre-Conditions: Valid integers
 * Post-Conditions: None
*****************************************************/
CommentCard::CommentCard(int t, int ct) : Item(t, ct)
{
}


/*****************************************************
 * Function: CommentCard::viewItem()
 * Description: Prints out a name and/or description
 * of the Item.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
void CommentCard::viewItem()
{
  if (containerType != Container::briefcase)
    cout << "Comment Card" << endl;
  else
  {
    if (type == Item::comment1)
    {
      cout << "Comment Card #1 - Prices are too high." << endl;
      cout << "Adding a free soda with every pizza purchase would be nice." << endl;
    }
    else if (type == Item::comment2)
    {
      cout << "Comment Card #2 - Prices are too high." << endl;
      cout << "Adding a free pizza to every order of five pizzas would be nice." << endl;
    }
    else
    {
      cout << "Comment Card #3 - The pizza is awesome!" << endl;
      cout << "Will definitely order again." << endl;
    }
  }
}


/*****************************************************
 * Function: CommentCard::~CommentCard()
 * Description: CommentCard destructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
*****************************************************/
CommentCard::~CommentCard()
{
}

