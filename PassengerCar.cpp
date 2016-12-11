/*********************************************************************
** Program Filename: PassengerCar.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class PassengerCar, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#include "PassengerCar.hpp"

//class constructor used to initialize data members below
PassengerCar::PassengerCar(std::string carName, std::string itemName) : TrainCar(carName)
{
	this->itemPresent = true;
	this->item = itemName;
}

/*********************************************************************
** Function: action
** Description: pure virtual function; drives whether a call to the search
function in this space results in finding an object or not.
** Parameters: pointer to a Hero object
** Pre-Conditions: none
** Post-Conditions: If first time calling this function, engageToggle
is set to true, if not, only console output is provided.
** Return: true bool if first time running function, false otherwise
*********************************************************************/
bool PassengerCar::action(Hero *heroIn)
{
	if (this->engageToggle == false)
	{	
		std::cout << "Mark Whalberg looks around. All the Bostonians on the " << carName << " are frantically screaming.\n";
		std::cout << "Mark steps up onto the seat and screams, 'I will stop this train!', in the thickest Boston accent anyone has ever heard.\n"
				  << "The crowd quiets down and everyone sits calmly.\n\n";
		this->engageToggle = true;
		return true;
	}
	else
	{
		std::cout << "Hmm, it sure is quite and calmn in here. It looks like there isn't anything left to do here.\n\n";
		return false;
	}
}

/*********************************************************************
** Function: search
** Description: pure virtual function; if engageToggle is set to true,
the space's item can be found and added to user's container(toolbelt).
If engageToggle is false, console hints to user to call action first
(which toggles engageToggle to true). Otherwise, if engageToggle is true
and item has already been found, hints to user there is nothing left
to find.
** Parameters: pointer to a Hero object
** Pre-Conditions: none
** Post-Conditions: If first time calling this function, and engageToggle
is true, itemPresent is set to false; otherwise no post conditions besides
console output.
** Return: true bool if first time running function and itemPresent is
set to true, false in all other scenarios.
*********************************************************************/
bool PassengerCar::search()
{
	std::cout << "Mark Whalberg looks, left, then right, and all around...\n";
	if (this->engageToggle == false)
	{
		std::cout << "Mark thinks to himself...if only everyone was calm and sitting down, then maybe I could find something useful here.\n";
		return false;
	}
	if (this->itemPresent == false)
	{
		std::cout << "I can't seem to find anything. There must not be anything helpful here.\n";
		return false;
	}
	else if (this->itemPresent == true)
	{
		std::cout << "What is this...it looks like a " << this->getItemName() << "!\n"\
			      << "This could be useful, maybe I should hang on to it.\n\n";
		this->itemPresent == false;
		return true;
	}
}

/*********************************************************************
** Function: getItemName
** Description: get function used to return the PassengerCar object's item data member
** Parameters: none
** Pre-Conditions: must be called on existing PassengerCar object
** Post-Conditions: none
** Return: item data member string
*********************************************************************/
std::string PassengerCar::getItemName()
{
	return this->item;
}

