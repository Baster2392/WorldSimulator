#pragma once
#include "Plant.h"
class PineBorscht : public Plant
{
private:
	void killAnimalAround();

public:
	PineBorscht(World* wolrd, int positionX, int positionY);

	void action();
	void breed();
};

