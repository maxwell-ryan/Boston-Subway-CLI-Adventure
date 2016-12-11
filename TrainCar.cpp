/*********************************************************************
** Program Filename: TrainCar.cpp
** Author: Max Weinberger
** Date: 12/1/2016
** Description: The following file implements class TrainCar, which is
the base class that makesup the Boston "T" (subway).
** Input: None
** Output: None
*********************************************************************/

#include "TrainCar.hpp"

//class constructor used to initialize data members below
TrainCar::TrainCar(std::string carName)
{
	this->carName = carName;
	this->engageToggle = false;
}

/*********************************************************************
** Function: setLayout
** Description: set function used to create the shape of the subway/gameboard
layout. This allows the designer to decide what spaces are connect to each other
and at what directions.
** Parameters: TrainCar pointers (4 of them)
** Pre-Conditions: must be called on existing BostonT object
** Post-Conditions: TrainCar object is connect to 0 - 4 other TrainCar 
objects (could be connected to NULL, if simulating a wall)
** Return: none
*********************************************************************/
void TrainCar::setLayout(TrainCar *forward, TrainCar *backward, TrainCar *left, TrainCar *right)
{
	this->forward = forward;
	this->backward = backward;
	this->left = left;
	this->right = right;
}

/*********************************************************************
** Function: getCarName
** Description: get function used to return the TrainCar's name
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object
** Post-Conditions: none
** Return: carName data member (string)
*********************************************************************/
std::string TrainCar::getCarName()
{
	return this->carName;
}

/*********************************************************************
** Function: getForwaard
** Description: get function used to return a pointer to the TrainCar
in front of a TrainCar object
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object, forward
data member must be set
** Post-Conditions: none
** Return: forward data member (TrainCar pointer)
*********************************************************************/
TrainCar* TrainCar::getForward()
{
	return this->forward;
}

/*********************************************************************
** Function: getBackward
** Description: get function used to return a pointer to the TrainCar
behind a TrainCar object
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object, backward
data member must be set
** Post-Conditions: none
** Return: backward data member (TrainCar pointer)
*********************************************************************/
TrainCar* TrainCar::getBackward()
{
	return this->backward;
}

/*********************************************************************
** Function: getLeft
** Description: get function used to return a pointer to the TrainCar
to the left of a TrainCar object
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object, left
data member must be set
** Post-Conditions: none
** Return: left data member (TrainCar pointer)
*********************************************************************/
TrainCar* TrainCar::getLeft()
{
	return this->left;
}

/*********************************************************************
** Function: getRight
** Description: get function used to return a pointer to the TrainCar
to the right of a TrainCar object
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object, right
data member must be set
** Post-Conditions: none
** Return: right data member (TrainCar pointer)
*********************************************************************/
TrainCar* TrainCar::getRight()
{
	return this->right;
}

/*********************************************************************
** Function: toggleEngage
** Description: effectively a set function that takes no parameter, and
toggles the engageToggle data member to true only if it is currently false
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object, engageToggle
must be false for this function to do anything
** Post-Conditions: engageToggle set to true, if it was previously false
** Return: none
*********************************************************************/
void TrainCar::toggleEngage()
{
	if (engageToggle == false)
	{
		this->engageToggle = true;
	}
	else if (engageToggle == true)
	{
		//this->engageToggle = false; opted to remove this, left in case future additions would benefit from
	}
}

/*********************************************************************
** Function: toggleItem
** Description: effectively a set function that takes no parameter, and
toggles the itemPresent data member to false only if it is currently true
** Parameters: none
** Pre-Conditions: must be called on existing TrainCar object, itemPresent
must be true for this function to do anything
** Post-Conditions: itemPresent set to false, if it was previously true
** Return: none
*********************************************************************/
void TrainCar::toggleItem()
{
	if (itemPresent == true)
	{
		this->itemPresent = false;
	}
	else if (itemPresent == false)
	{
		//this->itemPresent = true; opted to remove this, left in case future additions would benefit from
	}
}