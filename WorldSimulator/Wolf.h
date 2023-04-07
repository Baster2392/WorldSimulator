#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(World* world, int positionX, int positionY);
	Wolf(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);
	void breed();
};

