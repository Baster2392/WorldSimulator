#pragma once
#include "Animal.h"

class Antelope : public Animal
{
protected:
	void move();

public:
	Antelope(World* world, int positionX, int positionY);
	Antelope(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	bool hasEscaped(Organism* organism);
	void breed();

};

