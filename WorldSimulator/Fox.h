#pragma once
#include "Animal.h"
class Fox : public Animal
{
private:


public:
	Fox(World* world, int positionX, int positionY);

	void action();
	bool hasEscaped(Organism* other);
};

