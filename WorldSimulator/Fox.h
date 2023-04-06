#pragma once
#include "Animal.h"
class Fox : public Animal
{
private:


public:
	Fox(World* world, int positionX, int positionY);

	void action();
	void breed();
	bool hasEscaped(Organism* other);
};

