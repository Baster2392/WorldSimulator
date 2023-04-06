#include "Wolf.h"

Wolf::Wolf(World* world, int positionX, int positionY)
	:Animal(world, 9, 5, positionX, positionY, 'W', "Wilk")
{

}

void Wolf::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Wolf* newWolf = new Wolf(this->world, newPositionX, newPositionY);
	this->world->addOrganism(newWolf);
	this->world->addCommunicat("Pojawilo sie nowe zwierze: Wilk");
}
