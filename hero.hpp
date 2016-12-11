/*********************************************************************
** Program Filename: hero.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class Hero, which serves
as main character object. This object tracks the story's Hero location
and also maintains a container with all items found by the Hero. 
** Input: None
** Output: None
*********************************************************************/

#ifndef HERO_HPP
#define HERO_HPP

#include "TrainCar.hpp"
#include "EngineCar.hpp"
#include "PassengerCar.hpp"
#include "VendingMachineCar.hpp"
#include "Closet.hpp"
#include "Caboose.hpp"

class Hero
{
private:
	bool alive;
	bool savior;
	bool superSpeed;
	int maxToolbeltCapacity;
	TrainCar *currentLocation;
	std::vector<std::string> toolbelt;
	std::string name;

public:
	Hero();
	void viewToolbelt();
	bool addItem(std::string);
	bool scanForItem(std::string);
	
	void setName(std::string);
	std::string getName();
	void setCurrentLocation(TrainCar*);
	TrainCar* getCurrentLocation();
	int getMaxToolbeltCapacity();
	bool getAlive();
	bool getSavior();
	bool getSuperSpeed();
	void setAlive(bool);
	void setSavior(bool);
	void setSuperSpeed(bool);
	void setMaxToolbeltCapacity(int);
};

#endif
