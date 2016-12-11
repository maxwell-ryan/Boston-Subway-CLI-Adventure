/*********************************************************************
** Program Filename: TrainCar.hpp
** Author: Max Weinberger
** Date: 12/1/2016
** Description: The following file declares class TrainCar, which is
the base class.
** Input: None
** Output: None
*********************************************************************/

#ifndef TRAINCAR_HPP
#define	TRAINCAR_HPP

#include <string>
#include <iostream>
#include <vector>
class Hero;
class TrainCar
{
protected:
	TrainCar *forward;
	TrainCar *backward;
	TrainCar *left;
	TrainCar *right;

	bool engageToggle;
	bool itemPresent;

	std::string carName;
	
public:
	//constructor to setup object
	TrainCar(std::string);

	//function to orient and layout game map
	void setLayout(TrainCar*, TrainCar*, TrainCar*, TrainCar*);

	//get functions to retrieve neighboring car and related names
	TrainCar* getForward();
	TrainCar* getBackward();
	TrainCar* getLeft();
	TrainCar* getRight();
	std::string getCarName();
	
	void toggleEngage();
	void toggleItem();

	//pure virtual functions for derived classes
	virtual bool action(Hero*) = 0;
	virtual bool search() = 0;
	virtual std::string getItemName() = 0;

};

#endif
