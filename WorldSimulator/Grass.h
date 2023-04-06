#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(World* wolrd, int positionX, int positionY);

	void breed();
};

