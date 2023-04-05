#pragma once
#include "Organism.h"
class Plant : Organism
{
private:

public:
	// constructors
	Plant(World* world, int power, int positionX, int positionY, char icon, const char* name);

	void action();
	void breed();
};

