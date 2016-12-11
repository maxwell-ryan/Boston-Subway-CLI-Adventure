/*********************************************************************
** Program Filename: hero.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class Hero, which serves as 
the main character object.
** Input: None
** Output: None
*********************************************************************/

#include "hero.hpp"

//class constructor used to initialize data members below
Hero::Hero()
{
	currentLocation = NULL;
	this->alive = true;
	this->savior = false;
	this->superSpeed = false;
	this->maxToolbeltCapacity = 2;
}

/*********************************************************************
** Function: viewToolbelt
** Description: function which determines if the Hero's toolbelt is empty,
if so, the user is notified. If not, function outputs the contents of
the toolbelt order, via a for loop
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: toolbelt contents displayed to console
** Return: none
*********************************************************************/
void Hero::viewToolbelt()
{
	if (toolbelt.size() == 0)
	{
		std::cout << "Dang, it looks like my toolbelt is empty, that isn't very useful.\n";
	}
	else
	{
		std::cout << "Let's see, my toolbelt has: \n";

		for (int counter = 0; counter < toolbelt.size(); counter++)
		{
			std::cout << (counter + 1) << ". " << toolbelt[counter] << "\n";
		}
	}
}

/*********************************************************************
** Function: scanForItem
** Description: function used to quickly identify if Hero toolbelt
contains a particular item passed as a parameter
** Parameters: string
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: true bool is returned if Hero toolbelt contains string/item
argument, false returned otherwise
*********************************************************************/
bool Hero::scanForItem(std::string itemIn)
{
	for (int x = 0; x < toolbelt.size(); x++)
	{
		if (toolbelt.at(x) == itemIn)
		{
			return true;
		}
	}
	return false;
}

/*********************************************************************
** Function: addItem
** Description: function used to add items to Hero object's toolbelt
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: toolbelt data member (vector) contain one additional
item, as long as toolbelt has space
** Return: savior bool data memmber
*********************************************************************/
bool Hero::addItem(std::string itemIn)
{
	if (toolbelt.size() < maxToolbeltCapacity)	//if toolbelt is not full, add item
	{
		toolbelt.push_back(itemIn);
		std::cout << "Mark places the " << itemIn << " into his toolbelt.\nToolbelt now contains:\n";
		for (int counter = 0; counter < toolbelt.size(); counter++)
			{
				std::cout << (counter + 1) << ". " << toolbelt[counter] << "\n";
			}
		std::cout << std::endl;
		return true;
	}
	else if (toolbelt.size() >= maxToolbeltCapacity)	//if toolbelt is full ask user if they would like to drop an item and if so, which
	{
		int dropChoice;
		std::cout << "Shoot, my toolbelt is full. I'll have to drop an item before adding " << itemIn << "\n";
		std::cout << "Would you like to drop an item to add " << itemIn << "? 1. Yes 2. No\n\n";
		std::cin >> dropChoice;
		while (dropChoice < 1 || dropChoice > 2)
		{
			std::cout << "I didn't get that. 1. Yes 2. No\n\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> dropChoice;
		}
		if (dropChoice == 1)
		{
			//show user current toolbelt items to aid choice in what to drop
			viewToolbelt();
			
			//seek user input for what item to drop
			std::cout << "What item would you like to drop?\n";
			int itemDrop;
			std::cin >> itemDrop;
			while (itemDrop < 1 || itemDrop > toolbelt.size())
			{
				std::cout << "That isn't a valid item. Select 1 - " << toolbelt.size() << ".\n";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cin >> itemDrop;
			}
			
			//once user decides, remove that item from the toolbelt (vector) and then add item initially requested to be added
			int removedElement = itemDrop - 1;
			std::string removedItem = toolbelt.at(removedElement);
			toolbelt.erase(toolbelt.begin()+ removedElement);
			std::cout << "Mark rips " << removedItem << " off of his toolbelt and hucks it out the window. Hopefully he didn't need it.\n\n";
			toolbelt.push_back(itemIn);

			//show user what item was added and current toolbelt items
			std::cout << "Mark places the " << itemIn << "into his toolbelt.\nToolbelt now contains:\n";
			for (int counter = 0; counter < toolbelt.size(); counter++)
			{
				std::cout << (counter + 1) << ". " << toolbelt[counter] << "\n";
			}
			std::cout << std::endl;
			return true;
		}
		else
		{
			//if user opts to not drop an item, return to game
			return false;
		}
	}
}

/*********************************************************************
** Function: setMaxToolbeltCapacity
** Description: set function used to change the Hero object's maxToolbeltCapacity
data member
** Parameters: int
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: maxToolbeltCapacity data member set to argument passed
** Return: none
*********************************************************************/
void Hero::setMaxToolbeltCapacity(int maxToolbeltCapacity)
{
	this->maxToolbeltCapacity = maxToolbeltCapacity;
}

/*********************************************************************
** Function: getName
** Description: get function used to return the Hero object's name
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: name data member string
*********************************************************************/
int Hero::getMaxToolbeltCapacity()
{
	return this->maxToolbeltCapacity;
}

/*********************************************************************
** Function: setName
** Description: set function used to change the Hero object's name
data member
** Parameters: string
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: name data member set to argument passed
** Return: none
*********************************************************************/
void Hero::setName(std::string name)
{
	this->name = name;
}

/*********************************************************************
** Function: getName
** Description: get function used to return the Hero object's name
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: name data member string
*********************************************************************/
std::string Hero::getName()
{
	return this->name;
}

/*********************************************************************
** Function: getCurrentLocation
** Description: get function used to return the Hero object's current
location
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: currentLocation data memmber pointer to TrainCar
*********************************************************************/
TrainCar* Hero::getCurrentLocation()
{
	return this->currentLocation;
}

/*********************************************************************
** Function: setCurrentLocation
** Description: set function used to change the Hero object's currentLocation
data member
** Parameters: pointer to TrainCar object
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: currentLocation data member set to argument passed
** Return: none
*********************************************************************/
void Hero::setCurrentLocation(TrainCar* newCurrentLocation)
{
	this->currentLocation = newCurrentLocation;
}

/*********************************************************************
** Function: getAlive
** Description: get function used to return the Hero object's current
alive data member (verify if Mark Whalberg is still alive)
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: alive bool data memmber
*********************************************************************/
bool Hero::getAlive()
{
	return this->alive;
}

/*********************************************************************
** Function: setAlive
** Description: set function used change the Hero object's current
alive data member
** Parameters: bool
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: alive data member set to argument passed
** Return: none
*********************************************************************/
void Hero::setAlive(bool boolIn)
{
	this->alive = boolIn;
}

/*********************************************************************
** Function: getSavior
** Description: get function used to return the Hero object's current
savior data member (verify if Mark Whalberg has saved Boston yet)
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: savior bool data memmber
*********************************************************************/
bool Hero::getSavior()
{
	return this->savior;
}

/*********************************************************************
** Function: setSavior
** Description: set function used change the Hero object's current
savior data member
** Parameters: bool
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: savior data member set to argument passed
** Return: none
*********************************************************************/
void Hero::setSavior(bool boolIn)
{
	this->savior = boolIn;
}

/*********************************************************************
** Function: getSuperSpeed
** Description: get function used to return the Hero object's current
superSpeed data member (verify if Mark Whalberg can move quicker than
the default)
** Parameters: none
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: none
** Return: superSpeed bool data memmber
*********************************************************************/
bool Hero::getSuperSpeed()
{
	return this->superSpeed;
}

/*********************************************************************
** Function: setSuperSpeed
** Description: set function used change the Hero object's current
superSpeed data member
** Parameters: bool
** Pre-Conditions: must be called on existing Hero object
** Post-Conditions: superSpeed data member set to argument passed
** Return: none
*********************************************************************/
void Hero::setSuperSpeed(bool boolIn)
{
	this->superSpeed = boolIn;
}