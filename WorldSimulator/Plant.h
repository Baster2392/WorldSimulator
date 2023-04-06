#pragma once
#include "Organism.h"
class Plant : public Organism
{
private:
	int randomNumberTo15();

protected:
	bool isBreeding();

public:
	// constructors
	Plant(World* world, int power, int positionX, int positionY, char icon, const char* name);

	void action();
	void breed();
	bool isPlant();
};

