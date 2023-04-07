#include "Nightshade.h"

Nightshade::Nightshade(World* world, int positionX, int positionY)
	:Plant(world, 99, positionX, positionY, 'J', "Wilcze jagody")
{
}

Nightshade::Nightshade(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns)
	:Plant(world, power, positionX, positionY, previousPositionX, previousPositionY, turns, 'J', "Wilcze jagody")
{
}

void Nightshade::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Nightshade* newNightshade = new Nightshade(this->world, newPositionX, newPositionY);
	world->addOrganism(newNightshade);
	world->addCommunicat("Pojawila sie nowa roslina: Wilcze jagody");
}

void Nightshade::specialEffectAfterKilled(Organism* other)
{
	other->killed(this);
}
