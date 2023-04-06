#include "Sheep.h"

Sheep::Sheep(World* world, int positionX, int positionY)
	:Animal(world, 3, 5, positionX, positionY, 'O', "Owca")
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
