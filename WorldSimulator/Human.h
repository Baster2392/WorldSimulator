#pragma once
#include "Animal.h"
class Human : public Animal
{
private:
	int direction;

protected:
	int delay;
	int boost;

public:
	Human(World* world, int positionX, int positionY);
	Human(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);
	Human(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns, int boost, int delay);

	// main functions
	void action();
	void collision(Organism* other);
	void specialAbility();

	// getters
	int getDirection();
	int getDelay();
	int getBoost();

	// setters
	void setDirection(int direction);
};

