#include "Animal.h"

Animal::Animal(World* world, int power, int initiative, int positionX, int positionY, char icon, const char* name)
	: Organism(world, power, initiative, positionX, positionY, positionX, positionY, 0, icon, name)
{
}

Animal::Animal(World* world, int power, int initiative, int positionX, int positionY, int previousPositionX, int previousPositionY, int turns, char icon, const char* name)
	:Organism(world, power, initiative, positionX, positionY, previousPositionX, previousPositionY, turns, icon, name)
{
}

void Animal::action()
{
	move();
}

bool Animal::isAnimal()
{
	return true;
}

void Animal::move()
{
	this->prevPositionX = this->positionX;
	this->prevPositionY = this->positionY;

	int direction = Organism::randomField();

	if (direction == UPPER_FIELD && this->getPositionY() > 0)
	{
		this->positionY--;
	}
	else if (direction == LOWER_FIELD && this->getPositionY() < world->getHeight() - 1)
	{
		this->positionY++;
	}
	else if (direction == RIGHT_FIELD && this->getPositionX() < world->getWidth() - 1)
	{
		this->positionX++;
	}
	else if (direction == LEFT_FIELD && this->getPositionX() > 0)
	{
		this->positionX--;
	}
}
