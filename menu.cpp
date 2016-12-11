/*********************************************************************
** Program Filename: menu.cpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file defines the menu functions forward
declared within menu.hpp
** Input: None
** Output: None
*********************************************************************/
#include "menu.hpp"

/*********************************************************************
** Function: determineNextLocation
** Description: returns a pointer to the next location desired based
on what was passed to the function (forward, backward, left, right)
** Parameters: BostonT object, int
** Pre-Conditions: must be called on existing BostonT object, integer
passed must be 1, 2, 3, 4
** Post-Conditions: none
** Return: pointer to TrainCar object
*********************************************************************/
TrainCar* determineNextLocation(BostonT subwayIn, int directionIn)
{
	TrainCar *nextLocation = NULL;
	switch (directionIn)
	{
	case 1: nextLocation = subwayIn.getHero()->getCurrentLocation()->getForward();
			break;
	case 2: nextLocation = subwayIn.getHero()->getCurrentLocation()->getBackward();
			break;
	case 3: nextLocation = subwayIn.getHero()->getCurrentLocation()->getLeft();
			break;
	case 4: nextLocation = subwayIn.getHero()->getCurrentLocation()->getRight();
			break;
	}

	return nextLocation;
}

/*********************************************************************
** Function: moveCharacter
** Description: moves the BostonT object character to the next location
requested
** Parameters: BostonT object, int
** Pre-Conditions: must be called on existing BostonT object, integer
passed must be 1, 2, 3, 4
** Post-Conditions: BostonT character moves to the location specified
** Return: none
*********************************************************************/
void moveCharacter(BostonT subwayIn, int directionIn)
{
	TrainCar *nextLocation = NULL;
	switch (directionIn)
	{
		case 1: nextLocation = subwayIn.getHero()->getCurrentLocation()->getForward();
				subwayIn.getHero()->setCurrentLocation(nextLocation);
				std::cout << "Mark Whalberg walks forward through the car doors and is now in the " << subwayIn.getHero()->getCurrentLocation()->getCarName() << ".\n";
				break;
		case 2: nextLocation = subwayIn.getHero()->getCurrentLocation()->getBackward();
				subwayIn.getHero()->setCurrentLocation(nextLocation);
				std::cout << "Mark Whalberg walks backward through the car doors and is now in the " << subwayIn.getHero()->getCurrentLocation()->getCarName() << ".\n";
				break;
		case 3: nextLocation = subwayIn.getHero()->getCurrentLocation()->getLeft();
				subwayIn.getHero()->setCurrentLocation(nextLocation);
				std::cout << "Mark Whalberg walks left through the car doors and is now in the " << subwayIn.getHero()->getCurrentLocation()->getCarName() << ".\n";
				break;
		case 4: nextLocation = subwayIn.getHero()->getCurrentLocation()->getRight();
				subwayIn.getHero()->setCurrentLocation(nextLocation);
				std::cout << "Mark Whalberg walks right through the car doors and is now in the " << subwayIn.getHero()->getCurrentLocation()->getCarName() << ".\n";
				break;
	}
}

/*********************************************************************
** Function: selectMove
** Description: gets user input to drive the next move location
** Parameters: int by reference
** Pre-Conditions: none
** Post-Conditions: reference parameter changed to 1, 2, 3, or 4 based
on user choice
** Return: none
*********************************************************************/
void selectMove(int &moveDirection)
{
	std::cout << "Where would you like to go to next?\n" << "1. Forward\n2. Backward\n3. Left\n4. Right\n";
	std::cin >> moveDirection;
	while (moveDirection < 1 || moveDirection > 4)
	{
		std::cout << "Invalid selection. Select: 1. Forward 2. Backward 3. Left 4. Right\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> moveDirection;
	}
}

/*********************************************************************
** Function: selectAction
** Description: gets user input to drive the next action type
** Parameters: int by reference
** Pre-Conditions: none
** Post-Conditions: reference parameter changed to 1, 2, 3, or 4 based
on user choice
** Return: none
*********************************************************************/
void selectAction(int &actionType)
{
	std::cout << "\n\nWhat would you like to do?\n" << "1. Search Area\n2. Action\n3. Move\n4. Give up saving Boston and quit\n";
	std::cin >> actionType;
	while (actionType < 1 || actionType > 4)
	{
		std::cout << "Mark Whalberg cannot do that. Select: 1. Search Area\n2. Action\n3. Moven\4. Give up saving Boston and quit\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> actionType;
	}
}

/*********************************************************************
** Function: displayTimer
** Description: outputs to the user the number of game time left
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: game time remaining output to console
** Return: none
*********************************************************************/
void displayTimer(int numberOfMoves)
{
	switch (numberOfMoves)
	{
	case 2: std::cout << "Hmm, I wonder how many stations there are before the end of the line?\n"
					  << "(--9-- STOPS REMAINING)\n";
		break;
	case 4: std::cout << "The loudspeaker turns on....'You have now reached North Station, next stop, Haymarket.'\n"
					  << "(--8-- STOPS REMAINING)\n";
		break;
	case 6: std::cout << "The loudspeaker turns on....'You have now reached Downtown Crossing, exit here for transfer to the Red and Silver lines; next stop, Chinatown.'\n"
					  << "(7 STOPS REMAINING)\n";
		break;
	case 8: std::cout << "The loudspeaker turns on....'You have now reached Back Bay, next stop, Mass Ave.'\n"
					  << "(6 STOPS REMAINING)\n";
		break;
	case 10: std::cout << "The loudspeaker turns on....'You have now reached Mass Ave, next stop, Ruggles.'\n"
					   << "(5 STOPS REMAINING)\n";
		break;
	case 12: std::cout << "The loudspeaker turns on....'You have now reached Ruggles, next stop, Roxbury Crossing.'\n"
					   << "(4 STOPS REMAINING)\n";
		break;
	case 14: std::cout << "The loudspeaker turns on....'You have now reached Roxbury Crossing, next stop, Jackson Square.'\n"
					   << "(3 STOPS REMAINING)\n";
		break;
	case 16: std::cout << "The loudspeaker turns on....'You have now reached Jackson Square, next stop, Stony Brook.'\nMark thinks to himself, time is running out only 2 more stops before the end of the line!\n"
					   << "(2 STOPS REMAINING)\n";
		break;
	case 18: std::cout << "The loudspeaker turns on....'You have now reached Stony Brook, next stop, Green Street.'\nOh no, only one more stop before this thing crashes!\n"
					   << "(1 STOP REMAINING)\n";
		break;
	case 20: std::cout << "The loudspeaker turns on....'You have now reached Green Street, next stop and the end of the line, Forest Hills.'\nMark sighs, this thing is surly going to crash if I don't stop it right now!\n"
					   << "(NO STOPS REMAINING!!!)\n";
		break;
	case 22: std::cout << "The loudspeaker turns on....'You have now approaching the end of the line, Forest Hills.'\n";
	}
}

/*********************************************************************
** Function: pause
** Description: pauses the game loop until the user hits enter
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game loops pauses until user hits enter
** Return: none
*********************************************************************/
void pause()
{
	std::cin.ignore(1000000, '\n');
	std::cout << "{Press **ENTER** to continue}\n";
	std::cin.clear();
	std::cin.clear();
	std::cin.ignore(1000000, '\n');
}

/*********************************************************************
** Function: beginningPause
** Description: pauses the start of the game until the user hits enter
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game loop doesn't start until user hits enter
** Return: none
*********************************************************************/
void beginningPause()
{	
	std::cout << "{Press **ENTER** to begin your heroic adventure}\n";
	std::cin.ignore(1000000, '\n');
}