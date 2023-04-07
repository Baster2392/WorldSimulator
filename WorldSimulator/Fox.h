#pragma once
#include "Animal.h"

class Fox : public Animal
{
private:


public:
	Fox(World* world, int positionX, int positionY);
	Fox(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void action();
	void breed();
	bool hasEscaped(Organism* other);
};

