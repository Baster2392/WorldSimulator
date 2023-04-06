#pragma once
#include "Plant.h"
class Dandelion : public Plant
{
public:
	Dandelion(World* world, int positionX, int positionY);

	void breed();
};

