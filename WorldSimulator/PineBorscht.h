#pragma once
#include "Plant.h"
class PineBorscht : public Plant
{
private:
	void killAnimalAround();

public:
	PineBorscht(World* wolrd, int positionX, int positionY);
	PineBorscht(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void action();
	void breed();
};

