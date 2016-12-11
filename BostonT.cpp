/*********************************************************************
** Program Filename: BostonT.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines class BostonT, which serves as
the game's board/map.
** Input: None
** Output: None
*********************************************************************/

#include "BostonT.hpp"

/*********************************************************************
** Function: getHero
** Description: get function used to return the game's Hero object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: hero data member (a Hero object)
*********************************************************************/
Hero* BostonT::getHero()
{
	return this->hero;
}

/*********************************************************************
** Function: getEngine
** Description: get function used to return the game's EngineCar object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: EngineCar pointer
*********************************************************************/
EngineCar* BostonT::getEngine()
{
	return this->Engine;
}

/*********************************************************************
** Function: getSnackBar
** Description: get function used to return the game's VendingMachineCar object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: VendingMachineCar pointer
*********************************************************************/
VendingMachineCar* BostonT::getSnackBar()
{
	return this->SnackBar;
}

/*********************************************************************
** Function: getCar1
** Description: get function used to return the game's PassengerCar (1) object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: PassengerCar pointer
*********************************************************************/
PassengerCar* BostonT::getCar1()
{
	return this->Car1;
}

/*********************************************************************
** Function: getCar2
** Description: get function used to return the game's PassengerCar (2) object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: PassengerCar pointer
*********************************************************************/
PassengerCar* BostonT::getCar2()
{
	return this->Car2;
}

/*********************************************************************
** Function: getCar3
** Description: get function used to return the game's PassengerCar (3) object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: PassengerCar pointer
*********************************************************************/
PassengerCar* BostonT::getCar3()
{
	return this->Car3;
}

/*********************************************************************
** Function: getRearEngine
** Description: get function used to return the game's (rear) EngineCar object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: EngineCar pointer
*********************************************************************/
Caboose* BostonT::getRearEngine()
{
	return this->RearEngine;
}

/*********************************************************************
** Function: getLeftCloset
** Description: get function used to return the game's (left) Closet object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: Closet pointer
*********************************************************************/
Closet* BostonT::getLeftCloset()
{
	return this->LeftCloset;
}

/*********************************************************************
** Function: getRightCloset
** Description: get function used to return the game's (right) Closet object
** Parameters: none
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: none
** Return: Closet pointer
*********************************************************************/
Closet* BostonT::getRightCloset()
{
	return this->RightCloset;
}

//class constructor used to outline the game board and the hero of the game
BostonT::BostonT()
{
	//first create Hero object and set object data member to that Hero object; also name object Mark Whalberg, the true hero of the game
	this->hero = new Hero;
	hero->setName("Mark Whalberg");

	Engine = new EngineCar("Conductor Car", "Conductor Car Blueprints");
	SnackBar = new VendingMachineCar("Snack Bar Car", " ");
	Car1 = new PassengerCar("First Class Cabin Car", "Conductor's Key");
	Car2 = new PassengerCar("Second Class Cabin Car", "Clothing Hanger");
	Car3 = new PassengerCar("Rear Cabin Car", "Metal Pick");
	RearEngine = new Caboose("Rear Conductor Car", "New England Patriots Jacket");
	LeftCloset = new Closet("Left Rear Conductor Closet", "Cell Phone");
	RightCloset = new Closet("Right Rear Conductor Closet", "Crowbar");

	//now that all TrainCar derived objects have been instantiated, we can initialize each car's pointer locations
	Car3->setLayout(Car2, RearEngine, NULL, NULL);
	Car2->setLayout(Car1, Car3, NULL, NULL);
	Car1->setLayout(SnackBar, Car2, NULL, NULL);
	Engine->setLayout(NULL, SnackBar, NULL, NULL);
	SnackBar->setLayout(Engine, Car1, NULL, NULL);
	RearEngine->setLayout(Car3, NULL, LeftCloset, RightCloset);
	LeftCloset->setLayout(NULL, RearEngine, NULL, NULL);
	RightCloset->setLayout(NULL, RearEngine, NULL, NULL);
	
	//additionally, can now set Mark Whalberg's starting location as all TrainCar objects have been defined
	hero->setCurrentLocation(Car3);
}
