/*********************************************************************
** Program Filename: BostonT.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class BostonT. This class 
serves as the game map/board. The name "BostonT" comes from the "T" in 
Boston. "T" is what the subway is called. Thus, this class should be 
viewed as/is a subway. The class has TrainCars, which makeup the 
subway train.
** Input: None
** Output: None
*********************************************************************/

#ifndef BOSTONT_HPP
#define BOSTONT_HPP

#include "hero.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class BostonT
{
private:
	Hero *hero;
	EngineCar *Engine;
	VendingMachineCar *SnackBar;
	PassengerCar *Car1;
	PassengerCar *Car2;
	PassengerCar *Car3;
	Caboose *RearEngine;
	Closet *LeftCloset;
	Closet *RightCloset;
	
public:
	BostonT();
	//~BostonT();
	Hero* getHero();
	EngineCar* getEngine();
	VendingMachineCar* getSnackBar();
	PassengerCar* getCar1();
	PassengerCar* getCar2();
	PassengerCar* getCar3();
	Caboose* getRearEngine();
	Closet* getLeftCloset();
	Closet* getRightCloset();
};

#endif