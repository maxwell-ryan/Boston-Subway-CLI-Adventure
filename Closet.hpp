/*********************************************************************
** Program Filename: Closet.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file declares class Closet, which is
derived from base class: TrainCar.
** Input: None
** Output: None
*********************************************************************/

#ifndef CLOSET_HPP
#define CLOSET_HPP

#include "TrainCar.hpp"
#include "hero.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


class Closet : public TrainCar
{
private:
	std::string item;
	bool carSearched;

public:
	Closet(std::string, std::string);
	virtual std::string getItemName();
	virtual bool action(Hero*);
	virtual bool search();
};

#endif
