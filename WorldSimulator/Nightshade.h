#pragma once
#include "Plant.h"
class Nightshade : public Plant
{
public:
	Nightshade(World* world, int positionX, int positionY);

	void breed();
	void specialEffectAfterKilled(Organism* other);
};

