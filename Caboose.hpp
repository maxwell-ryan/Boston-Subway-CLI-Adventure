/*********************************************************************
** Program Filename: Caboose.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class Caboose, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#ifndef CABOOSE_HPP
#define CABOOSE_HPP

#include "hero.hpp"
#include "TrainCar.hpp"
#include <iostream>
#include <vector>
#include <string>

class Caboose : public TrainCar
{
private:
	std::string item;
	bool carSearched;

public:
	Caboose(std::string, std::string);
	virtual std::string getItemName();
	virtual bool action(Hero*);
	virtual bool search();
};

#endif