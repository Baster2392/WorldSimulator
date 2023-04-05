#pragma once
#include "Animal.h"
class Turtle : public Animal
{
public:
	Turtle(World* world, int positionX, int positionY);

	void action();
	bool isAttackDefended(Organism* other);
};

