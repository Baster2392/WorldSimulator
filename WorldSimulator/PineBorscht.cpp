#include "PineBorscht.h"

void PineBorscht::killAnimalAround()
{
	Organism* other;
	other = world->getOrganismAtPosition(this->positionX + 1, this->positionY);

	if (other != nullptr)
	{
		if (other->isAnimal())
		{
			other->killed(this);
		}
	}

	other = world->getOrganismAtPosition(this->positionX - 1, this->positionY);

	if (other != nullptr)
	{
		if (other->isAnimal())
		{
			other->killed(this);
		}
	}

	other = world->getOrganismAtPosition(this->positionX, this->positionY + 1);

	if (other != nullptr)
	{
		if (other->isAnimal())
		{
			other->killed(this);
		}
	}

	other = world->getOrganismAtPosition(this->positionX, this->positionY - 1);

	if (other != nullptr)
	{
		if (other->isAnimal())
		{
			other->killed(this);
		}
	}
}

PineBorscht::PineBorscht(World* wolrd, int positionX, int positionY)
	:Plant(wolrd, 10, positionX, positionY, 'B', "Barszcz sosnowskiego")
{
}

PineBorscht::PineBorscht(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns)
	:Plant(world, power, positionX, positionY, previousPositionX, previousPositionY, turns, 'B', "Barszcz sosnowskiego")
{
}

void PineBorscht::action()
{
	killAnimalAround();

	if (isBreeding())
	{
		this->breed();
	}
}

void PineBorscht::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	PineBorscht* newPineBorscht = new PineBorscht(this->world, newPositionX, newPositionY);
	world->addOrganism(newPineBorscht);
	world->addCommunicat("Pojawila sie nowa roslina: Barszcz sosnowskiego");
}
