#include "Guarana.h"

Guarana::Guarana(World* world, int positionX, int positionY)
	:Plant(world, 0, positionX, positionY, 'G', "Guarana")
{
}

Guarana::Guarana(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns)
	:Plant(world, power, positionX, positionY, previousPositionX, previousPositionY, turns, 'G', "Guarana")
{
}

void Guarana::specialEffectAfterKilled(Organism* other)
{
	world->addCommunicat(other->getName() + " zyskuje 3 pkt ataku");
	other->setPower(other->getPower() + 3);
}

void Guarana::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Guarana* newGuarana = new Guarana(this->world, newPositionX, newPositionY);
	world->addOrganism(newGuarana);
	world->addCommunicat("Pojawila sie nowa roslina: Guarana");
}
