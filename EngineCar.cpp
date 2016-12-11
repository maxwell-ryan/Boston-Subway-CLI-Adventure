/*********************************************************************
** Program Filename: EngineCar.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class EngineCar, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#include "EngineCar.hpp"

//class constructor used to initialize data members below
EngineCar::EngineCar(std::string carName, std::string itemName) : TrainCar(carName)
{
	this->itemPresent = true;
	this->item = itemName;
	this->carSearched = false;
}

/*********************************************************************
** Function: action
** Description: pure virtual function; drives the user to win the game.
Cannot be run unless the EngineCar search function has been called first.
If it is called, and the user contains a Crowbar in their toolbelt, the user
will win and true is returned to indicate the action was sucessful and the 
game's while loop can terminate.
** Parameters: pointer to a Hero object
** Pre-Conditions: to fully run, besides console output to give user
hints, must be run after the object's search function is called/selected.
** Post-Conditions: If the user has a toolbelt, the function returns a
true bool to indicate a win state; otherwise console output is provided
to the user but a false bool is returned.
** Return: bool based on game state
*********************************************************************/
bool EngineCar::action(Hero *heroIn)
{
	if (this->carSearched == false) //if user has used search function on object yet, hint to search first
	{
		std::cout << "I haven't found anything to do here yet.\n";
		return false;
	}
	else if (this->carSearched == true)
	{
		if (this->engageToggle == false)	//if user has searched but hasn't used action yet, execute below
		{
			std::cout << "It looks like there is a crawl space under that metal floor cutout.\n";
			if (heroIn->scanForItem("Crowbar"))	//if user has a Crowbar in inventory, allow win state to occur and return true
			{
				std::cout << "Good thing I picked up this crowbar...\n\n***Mark prys the floor up with the Crowbar***\n\n"
					<< "Look, the fuel line. If I just detach it, the motor will die.\nMark rips the fuel line out...\n";
				heroIn->setSavior(true);
				this->engageToggle == true;
				return true;
			}
			else
			{
				std::cout << "If only I had a Crowbar to lift the heavy floor, I could see what is underneath.\n\n";
				return false;				//if user does not have a Crowbar, hint that they should find one and return false
			}
		}
		else
		{
			std::cout << "Hmm, it looks like I have already done that.\n";
			return false;
		}
	}
}

/*********************************************************************
** Function: search
** Description: pure virtual function; allows the user to find the
object's item, only if it hasn't been found yet. Also sets carSearched
bool to true so the user can sucesfully call the action object function 
to win the game, if they have a Crowbar (see above)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: carSearched bool set to true. Console output given
to user to indicate what they should do next
** Return: bool to indicate if an item was found (true), or false
if the item was already found (second time in the room or second time searching)
*********************************************************************/
bool EngineCar::search()
{
	if (this->itemPresent == false)
	{
		std::cout << "I can't seem to find anything. There must not be anything helpful here.\n";
		this->carSearched = true;
		return false;
	}
	else if (this->itemPresent == true)
	{
		std::cout << "What is this...it looks like I found " << this->getItemName() << "!\n"\
				  << "This could be useful, I better hang out to it. Oh look, there is metal floor cutout in this room.\n";
		this->carSearched = true;
		return true;
	}
}

/*********************************************************************
** Function: getItemName
** Description: get function used to return the EngineCar object's item data member
** Parameters: none
** Pre-Conditions: must be called on existing EngineCar object
** Post-Conditions: none
** Return: item data member string
*********************************************************************/
std::string EngineCar::getItemName()
{
	return this->item;
}
