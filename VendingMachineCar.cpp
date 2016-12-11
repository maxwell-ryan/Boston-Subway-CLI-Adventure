/*********************************************************************
** Program Filename: VendingMachineCar.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class VendingMachineCar, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#include "VendingMachineCar.hpp"

//class constructor used to initialize data members below
VendingMachineCar::VendingMachineCar(std::string carName, std::string itemName) : TrainCar(carName)
{
	this->itemPresent = true;
	this->item = itemName;
	this->carSearched = false;
}

/*********************************************************************
** Function: action
** Description: pure virtual function; allows the user to drink a Red
Bull found via the object's search function. If Red Bull is consumed,
user's superSpeed data member is set to true. This allows the user
to move around more per tick of the game clock. 
Note: this essentially doubles the remaining game time for the user
allowing them more time to solve the game's problem.
** Parameters: pointer to a Hero object
** Pre-Conditions: none
** Post-Conditions: If carSearched is true, and itemPresent is true,
carSearched is set to true, argument's superSpeed data member is set to
true via the setSuperSpeed function, and itemPresent is set to false.
** Return: false bool
*********************************************************************/
bool VendingMachineCar::action(Hero *heroIn)
{
	if (this->carSearched == false)
	{
		std::cout << "I haven't found anything to do here yet.\n\n";
		return false;
	}
	else if (this->carSearched == true && this->itemPresent == true)
	{
		std::cout << "Maybe I should chug one of those Red Bulls...\n[Mark Whalberg chugs a Red Bull and gains SUPER SPEED. He can now move at a rate of two cars between stations.]\n\n";
		this->carSearched = true;
		heroIn->setSuperSpeed(true);
		this->itemPresent = false;
		return false;
	}
	else if (this->carSearched == true && this->itemPresent == false)
	{
		std::cout << "I better not chug another Red Bull. There aren't any bathrooms on the T.\n\n";
		return false;
	}
}

/*********************************************************************
** Function: search
** Description: pure virtual function; allows the user to identify a
refidgerator full of Red Bull, which then allows the action member
function to result in gaining the superSpeed ability. User cannot
drink a Red Bull via the action function until they user the search 
function first.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: carSearched data member set to false
** Return: false bool
*********************************************************************/
bool VendingMachineCar::search()
{
	if (this->itemPresent == false)
	{
		std::cout << "I can't seem to find anything else. There must not be anything helpful here.\n\n";
		this->carSearched = true;
		return false;
	}
	else if (this->itemPresent == true)
	{
		std::cout << "Look, a refridgerator full of of Red Bull.\n\n";
		this->carSearched = true;
		return false;
	}
}

/*********************************************************************
** Function: getItemName
** Description: get function used to return the VendingMachineCar object's item data member
** Parameters: none
** Pre-Conditions: must be called on existing VendingMachineCar object
** Post-Conditions: none
** Return: item data member string
*********************************************************************/
std::string VendingMachineCar::getItemName()
{
	return this->item;
}