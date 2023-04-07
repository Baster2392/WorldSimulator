#pragma once
#include "Plant.h"
class Nightshade : public Plant
{
public:
	Nightshade(World* world, int positionX, int positionY);
	Nightshade(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void breed();
	void specialEffectAfterKilled(Organism* other);
};

