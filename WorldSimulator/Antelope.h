#pragma once
#include "Animal.h"
class Antelope : public Animal
{
protected:
	void move();

public:
	Antelope(World* world, int positionX, int positionY);

	bool hasEscaped(Organism* organism);
};

