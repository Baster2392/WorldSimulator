#include "Fox.h"

Fox::Fox(World* world, int positionX, int positionY)
	:Animal(world, 3, 7, positionX, positionY, 'L', "Lis")
{
}

void Fox::action()
{
	int direction = Organism::randomField();
	int newPositionX = this->positionX, newPositionY = this->positionY;
	bool isSafe = false;

	if (direction == UPPER_FIELD && this->getPositionY() > 0)
	{
		newPositionY--;
	}
	else if (direction == LOWER_FIELD && this->getPositionY() < world->getHeight() - 1)
	{
		newPositionY++;
	}
	else if (direction == RIGHT_FIELD && this->getPositionX() < world->getWidth() - 1)
	{
		newPositionX++;
	}
	else if (direction == LEFT_FIELD && this->getPositionX() > 0)
	{
		newPositionX--;
	}

	Organism* targetOrganism = world->getOrganismAtPosition(newPositionX, newPositionY);

	if (targetOrganism != nullptr)
	{
		if (targetOrganism->getPower() > this->power)
		{
			goToSafeField();
		}
		else
		{
			this->positionX = newPositionX;
			this->positionY = newPositionY;
		}
	}
	else
	{
		this->positionX = newPositionX;
		this->positionY = newPositionY;
	}
}

void Fox::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Fox* newFox = new Fox(this->world, newPositionX, newPositionY);
	this->world->addOrganism(newFox);
	this->world->addCommunicat("Pojawilo sie nowe zwierze: Lis");
}

bool Fox::hasEscaped(Organism* other)
{
	if (other->getPower() > this->power)
	{
		goToSafeField();
		return true;
	}

	return false;
}
