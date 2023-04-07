#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(World* wolrd, int positionX, int positionY);
	Grass(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void breed();
};

