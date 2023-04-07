#include "Sheep.h"

Sheep::Sheep(World* world, int positionX, int positionY)
	:Animal(world, 3, 5, positionX, positionY, 'O', "Owca")
{
}

Sheep::Sheep(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns)
	:Animal(world, power, initiative, positionX, positionY, previousPositionX, previousPositionY, turns, 'O', "Owca")
{
}

void Sheep::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Sheep* newSheep = new Sheep(this->world, newPositionX, newPositionY);
	this->world->addOrganism(newSheep);
	this->world->addCommunicat("Pojawilo sie nowe zwierze: Owca");
}
