#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(World* wolrd, int positionX, int positionY);

	void specialEffectAfterKilled(Organism* other);
	void breed();
};

