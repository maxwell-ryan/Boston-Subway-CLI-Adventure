/*********************************************************************
** Program Filename: EngineCar.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class EngineCar, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#ifndef ENGINECAR_HPP
#define ENGINECAR_HPP

#include "TrainCar.hpp"
#include "hero.hpp"
#include <iostream>
#include <vector>
#include <string>

class EngineCar : public TrainCar
{
private:
	std::string item;
	bool carSearched;

public:
	EngineCar(std::string, std::string);
	virtual std::string getItemName();
	virtual bool action(Hero*);
	virtual bool search();
};

#endif
