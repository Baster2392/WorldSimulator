#include "Grass.h"

Grass::Grass(World* world, int positionX, int positionY)
	:Plant(world, 0, positionX, positionY, 'T', "Trawa")
{

}

void Grass::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Grass* newGrass = new Grass(this->world, newPositionX, newPositionY);
	world->addOrganism(newGrass);
	world->addCommunicat("Pojawila sie nowa roslina: Trawa");
}
