/*********************************************************************
** Program Filename: Closet.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class Closet, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#include "Closet.hpp"

//class constructor used to initialize data members below
Closet::Closet(std::string carName, std::string itemName) : TrainCar(carName)
{
	this->itemPresent = true;
	this->item = itemName;
	this->carSearched = false;
}

/*********************************************************************
** Function: action
** Description: pure virtual function; if user hasn't called this function
yet via the menu, user has a 50% chance to be successful call the engageToggle.
If engageToggle is set to true, subsequently calling the search function via 
the menu will allow the item to be found. If 50% is unsuccessuful, user can keep
trying until they are successful.

NOTE: this simulates attempting to open a rusted chest that is stuck shut

** Parameters: pointer to a Hero object
** Pre-Conditions: none
** Post-Conditions: If 50% chance hits, the engageToggle is set to true, which
allows the user to find the space item via a call to search function in the menu.
In all other scenarios, false is returned and engageToggle is not set to true.
** Return: true if chest is opened (50% chance hits), false in all other
scenarios
*********************************************************************/
bool Closet::action(Hero *heroIn)
{
	if (this->engageToggle == false)
	{
		int random = (rand() % 2);
		std::cout << "Hmm, a rusted chest, I wonder if I can get this open...\n";
		if (random == 1)
		{
			std::cout << "It is so rusted, I can't get it. Maybe if I keep trying I will.\n";
			return false;
		}
		else if (random == 0)
		{
			std::cout << "[BOOM, Mark Whalberg throws the chest to the ground in frustration!]\nLook, it opened!\n";
			this->engageToggle = true;
			return true;
		}
	}
	else if (this->engageToggle == true)
	{
		std::cout << "[Mark Whalberg thinks.. I cannot believe I got that rusted chest open, I wonder what is in here?]\n";
		return false;
	}
}

/*********************************************************************
** Function: search
** Description: pure virtual function; hints to the user that the space
contains a chest that may contain an item. (hints to user to try selecting
action within this space)
** Parameters: none
** Pre-Conditions: none, however, if action has been successfully completed
then the console output is different than if it hasn't been completed at
all or hasn't been succesful yet.
** Post-Conditions: console output provided to the user, if action has
been successfully completed, the space item is found.
** Return: true bool returned if action call already successful and item
has not yet been found. False bool returned if action has not been successful yet,
or if space item has already been found.
*********************************************************************/
bool Closet::search()
{
	if (this->itemPresent == false && this->engageToggle == true)
	{
		std::cout << "I can't seem to find anything else. All that for this one item? I hope it helps.\n\n";
		this->carSearched = true;
		return false;
	}
	else if (this->itemPresent == true && this->engageToggle == true)
	{
		std::cout << "What is this...it looks like a " << this->getItemName() << "!\n"\
			<< "Is this what the conductor was looking for?\n";
		this->carSearched = true;
		return true;
	}
	else if (this->itemPresent == true && this->engageToggle == false)
	{
		std::cout << "Look, a rusted chest.\n";
		return false;
	}
}

/*********************************************************************
** Function: getItemName
** Description: get function used to return the Closet object's item data member
** Parameters: none
** Pre-Conditions: must be called on existing Closet object
** Post-Conditions: none
** Return: item data member string
*********************************************************************/
std::string Closet::getItemName()
{
	return this->item;
}