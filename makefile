# this is my makefile

maxFinalProject: BostonT.o Caboose.o Closet.o EngineCar.o hero.o menu.o PassengerCar.o TrainCar.o VendingMachineCar.o main.o
	g++ BostonT.o Caboose.o Closet.o EngineCar.o hero.o menu.o PassengerCar.o TrainCar.o VendingMachineCar.o main.o -o maxFinalProject

BostonT.o: BostonT.cpp
	g++ -c BostonT.cpp

Caboose.o: Caboose.cpp
	g++ -c Caboose.cpp

Closet.o: Closet.cpp
	g++ -c Closet.cpp

EngineCar.o: EngineCar.cpp
	g++ -c EngineCar.cpp

hero.o: hero.cpp
	g++ -c hero.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

PassengerCar.o: PassengerCar.cpp
	g++ -c PassengerCar.cpp

TrainCar.o: TrainCar.cpp
	g++ -c TrainCar.cpp

VendingMachineCar.o: VendingMachineCar.cpp
	g++ -c VendingMachineCar.cpp

main.o: main.cpp
	g++ -c main.cpp

PRJ = maxFinalProject
OBJS = BostonT.o Caboose.o Closet.o EngineCar.o hero.o menu.o PassengerCar.o TrainCar.o VendingMachineCar.o main.o

clean:
	rm -f $(OBJS) $(PRJ)








	
