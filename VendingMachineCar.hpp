/*********************************************************************
** Program Filename: VendingMachineCar.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class VendingMachineCar, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#ifndef VENDINGMACHINECAR_HPP
#define VENDINGMACHINECAR_HPP

#include "TrainCar.hpp"
#include "hero.hpp"
#include <iostream>
#include <vector>
#include <string>

class VendingMachineCar : public TrainCar
{
private:
	std::string item;
	bool carSearched;

public:
	VendingMachineCar(std::string, std::string);
	virtual std::string getItemName();
	virtual bool action(Hero*);
	virtual bool search();
};

#endif
