#pragma once
#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(World* world, int positionX, int positionY);
	Turtle(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void action();
	void breed();
	bool isAttackDefended(Organism* other);
};

