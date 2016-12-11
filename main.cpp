/*********************************************************************
** Program Filename: main.hpp
** Author: Max Weinberger
** Date: 12/2/2016
** Description: The following file forward declares the main function
which instantiates the necessary game objects, controls the game loop,
and terminates the game at the correct time. Finally, cleans up heap
memory before fully terminating.
** Input: None
** Output: None
*********************************************************************/
#include "menu.hpp"

int main()
{
	srand(time(NULL));					//seed random once for entire program for use in Closet class
	BostonT OrangeLine;
	int timesMoved = 0;					//int tracks nubmer of times Mark Whalberg has moved
	int moveDirection;
	int actionType = 0;
	TrainCar *nextLocation = NULL;

	//introduce the user to the game objectives and scenario
	std::cout << "It is New Year's Eve in Boston, MA 2017.\n\nYou, the great Boston native, Mark Whalberg, awake from a nap on the 'T' (Boston's Subway) to a great commotion.\n"
		<< "Everyone is screaming and frantic.\n\nThe Conductor runs towards the back of the car screaming 'the train won't stop, we are only 8 stops from the end of the line,"
		<< " we are going to crash into it and die. If only I could find that Crowbar!\n\n[At that moment the conductor trips and is knocked unconcious, who will save the train now?]\n\n"
		<< "Mark Whalberg stands up and assess the situation, can he save the train from crashing?\n" << "[Remember: Mark is strong, but only quick enough to move to one other area between each station!]\n";
	beginningPause();

	//orient user and hint that they have a container that can hold items
	std::cout << "You recall that you are riding the Orange Line and are in the " << OrangeLine.getHero()->getCurrentLocation()->getCarName() << "." << " Look, I have a toolbelt!\n";
	OrangeLine.getHero()->viewToolbelt();
	std::cout << std::endl;

	//code to drive next round of character action
	do 
	{
		selectAction(actionType);
		if (actionType == 1)
		{
			bool added;
			added = OrangeLine.getHero()->getCurrentLocation()->search();
			if (added == true)
			{
				OrangeLine.getHero()->addItem(OrangeLine.getHero()->getCurrentLocation()->getItemName());
				OrangeLine.getHero()->getCurrentLocation()->toggleItem();
			}
		}
		else if (actionType == 2)
		{
			OrangeLine.getHero()->getCurrentLocation()->action(OrangeLine.getHero());
		}
		else if (actionType == 3)
		{
			selectMove(moveDirection);		//pass moveDirection by reference
			while (determineNextLocation(OrangeLine, moveDirection) == NULL)
			{
				std::cout << "There doesn't seem to be a door leading that direction. Try another direction.\n";
				selectMove(moveDirection);
			}
			//move character in direction user decided
			moveCharacter(OrangeLine, moveDirection);
			
			//display timer and determine how much to increment, depending if Hero has gained SUPER SPEED or not
			displayTimer(timesMoved);
			if ( (OrangeLine.getHero()->getSuperSpeed() == true) )
			{
				timesMoved++;
			}
			else
			{
				timesMoved += 2;
			}
		}
		//before allowing more character movement, ensure time limit (subway stations remaining) has not lapsed
		if (timesMoved >= 22)
		{
			OrangeLine.getHero()->setAlive(false);
		}

		if (actionType != 4)
		{
			pause();
		}
	} while (actionType != 4 && OrangeLine.getHero()->getAlive() == true && OrangeLine.getHero()->getSavior() != true);

	//if user opts to quit, providing quitting outcome output
	if (actionType == 4)
	{
		std::cout << "Mark Whalberg jumped off the train and gave up, who knew Mark Whalberg ever gives up.\n"
				  << "The Orange Line has barreled into Forest Hills station resulting in a huge explosion and death.\nAll passengers have died, you HAVE LOST!\n\n"
				  << "-----------------------\n" << "|      GAME OVER      |\n" << "-----------------------\n";
	}

	//if user wins, providing winning outcome output
	if (OrangeLine.getHero()->getSavior())
	{
		std::cout << "The train halts before barrelling into the end of the line and killing everyone!\nYou have successfully guided Mark to the heroic, savior path.\nYou ARE VICTORIOUS!\n\n"
				  << "-----------------------\n" << "|      GAME OVER      |\n" << "-----------------------\n";
	}

	//if user lost, providing loosing outcome output
	if (OrangeLine.getHero()->getAlive() == false)
	{
		std::cout << "The train plows forward at full speed into Forrest Hills. The entire station blows up and all passengers die, including Mark Whalberg!\nYou HAVE LOST!\n\n"
			<< "-----------------------\n" << "|      GAME OVER      |\n" << "-----------------------\n";
	}

	//now that program has finished running and the user has been notified of outcome, clean up heap memory
	delete OrangeLine.getHero();
	delete OrangeLine.getEngine();
	delete OrangeLine.getSnackBar();
	delete OrangeLine.getCar1();
	delete OrangeLine.getCar2();
	delete OrangeLine.getCar3();
	delete OrangeLine.getRearEngine();
	delete OrangeLine.getLeftCloset();
	delete OrangeLine.getRightCloset();

	return 0;
}