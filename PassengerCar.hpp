/*********************************************************************
** Program Filename: PassengerCar.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class PassengerCar, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#ifndef PASSENGERCAR_HPP
#define PASSENGERCAR_HPP

#include "TrainCar.hpp"
#include "hero.hpp"
#include <iostream>
#include <vector>
#include <string>

class PassengerCar : public TrainCar
{
private:
	std::string item;

public:
	PassengerCar(std::string, std::string);
	virtual std::string getItemName();
	virtual bool action(Hero*);
	virtual bool search();
};

#endif