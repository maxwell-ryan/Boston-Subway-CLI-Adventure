/*********************************************************************
** Program Filename: menu.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file forward declares various functions
used to drive the menu functionality in main.cpp
** Input: None
** Output: None
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "hero.hpp"
#include "BostonT.hpp"
#include <iostream>
#include <vector>
#include <string>

void moveCharacter(BostonT, int);
TrainCar* determineNextLocation(BostonT, int);
void selectMove(int&);
void selectAction(int&);
void displayTimer(int);
//try using a function to slow the rapid text output to console
void pause();
void beginningPause();

#endif

