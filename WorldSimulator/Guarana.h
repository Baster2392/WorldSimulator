#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(World* wolrd, int positionX, int positionY);
	Guarana(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns);

	void specialEffectAfterKilled(Organism* other);
	void breed();
};

