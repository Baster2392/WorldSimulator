#pragma once
#include "Animal.h"
class Human : public Animal
{
private:
	int direction;
	int delay;

public:
	Human(World* world, int positionX, int positionY);

	// main functions
	void action();
	void collision(Organism* other);
	void specialAbility();

	// getters
	int getDirection();

	// setters
	void setDirection(int direction);
};

