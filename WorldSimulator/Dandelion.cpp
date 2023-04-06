#include "Dandelion.h"

Dandelion::Dandelion(World* world, int positionX, int positionY)
	:Plant(world, 0, positionX, positionY, 'M', "Mlecz")
{
}

void Dandelion::breed()
{
	for (int i = 0; i < 3; i++)
	{
		int newPositionX = this->positionX;
		int newPositionY = this->positionY;

		world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

		if (this->positionX == newPositionX && this->positionY == newPositionY)
		{
			return;
		}

		Dandelion* newDandelion = new Dandelion(this->world, newPositionX, newPositionY);
		world->addOrganism(newDandelion);
		world->addCommunicat("Pojawila sie nowa roslina: Mlecz");
	}
}
