#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(World* world, int positionX, int positionY);
	Sheep(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);
	void breed();
};

