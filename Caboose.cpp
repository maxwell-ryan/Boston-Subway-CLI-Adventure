/*********************************************************************
** Program Filename: Caboose.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class Caboose, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#include "Caboose.hpp"

//class constructor used to initialize data members below
Caboose::Caboose(std::string carName, std::string itemName) : TrainCar(carName)
{
	this->itemPresent = true;
	this->item = itemName;
	this->carSearched = false;
}

/*********************************************************************
** Function: action
** Description: pure virtual function; if the user has searched first,
allows user to interact with co-conductor and receive a new toolbelt 
which holds 3 items instead of 2. This is only available in this car
(i.e. this object type)
** Parameters: pointer to a Hero object
** Pre-Conditions: none, to get new toolbelt with additional capacity,
must be called after search function is called
** Post-Conditions: if user has called search first, user gains a 
new toolbelt with a capactiy of 3 instead of just 2 (this is done
by setting the hero object's toolbeltCapacity data member to 3 via
the setMaxToolbeltCapacity function.
** Return: true bool if search performed first, false if search not
conducted first
*********************************************************************/
bool Caboose::action(Hero *heroIn)
{
	if (this->carSearched == false)
	{
		std::cout << "Maybe I should look around first.\n";
		return false;
	}
	else if (this->carSearched == true)
	{
		std::cout << "Mark bends down and picks up the co-conductor off the ground and says, 'I can get to the front in time'.\n"
				  << "The co-conductor says, 'well then, this can help you more than me.'\n"
			      << "[Mark has acquired a new toolbelt and can now hold 3 ITEMS instead of just 2 ITEMS.]\n";
		heroIn->setMaxToolbeltCapacity(3);
		return true;
	}
}

/*********************************************************************
** Function: search
** Description: pure virtual function; hints to the user that two
closets are adjacent to the space currently in, also hints to the user
that the Crowbar is key to the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: console output provided to the user, if search
has not yet been conducted yet, the itemPresent data member is set to 
false and the carSearched data member is set to false
** Return: false bool is returned everytime
*********************************************************************/
bool Caboose::search()
{
	if (this->itemPresent == true)
	{
		std::cout << "[Mark Whalberg scans the room and sees a co-conductor huddle on the ground. He looks at Mark and says 'I'll never make it to the most forward car in time.]\n"
			      << "[Mark looks around further and notices two side closets. Hmm...\n";
		this->itemPresent = false;
		this->carSearched = true;
		return false;
	}
	else if (this->itemPresent == false)
	{
		std::cout << "[The co-conductor cries, 'I thought my conductor was coming to get the Crowbar...']\n";
		return false;
	}
}

/*********************************************************************
** Function: getItemName
** Description: get function used to return the Caboose object's item data member
** Parameters: none
** Pre-Conditions: must be called on existing Caboose object
** Post-Conditions: none
** Return: item data member string
*********************************************************************/
std::string Caboose::getItemName()
{
	return this->item;
}