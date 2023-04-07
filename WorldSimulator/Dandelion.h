#pragma once
#include "Plant.h"

class World;

class Dandelion : public Plant
{
public:
	Dandelion(World* world, int positionX, int positionY);
	Dandelion(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void breed();
};

