#include "Human.h"

Human::Human(World* world, int positionX, int positionY)
	: Animal(world, 4, 4, positionX, positionY, 'C', "Czlowiek")
{
	this->direction = 0;
	this->delay = 0;
}

void Human::action()
{
	this->prevPositionX = this->positionX;
	this->prevPositionY = this->positionY;

	if (this->direction == UPPER_FIELD && this->getPositionY() > 0)
	{
		this->positionY--;
	}
	else if (this->direction == LOWER_FIELD && this->getPositionY() < world->getHeight() - 1)
	{
		this->positionY++;
	}
	else if (this->direction == RIGHT_FIELD && this->getPositionX() < world->getWidth() - 1)
	{
		this->positionX++;
	}
	else if (this->direction == LEFT_FIELD && this->getPositionX() > 0)
	{
		this->positionX--;
	}

	if (this->power > 5)
	{
		this->power--;

		if (this->power == 5)
		{
			this->delay = 5;
		}
	}
	else if (this->delay > 0)
	{
		this->delay--;
	}
}

void Human::collision(Organism* other)
{
	if (!isSameSpecies(this, other))
	{
		fight(this, other);
	}
}

void Human::specialAbility()
{
	if (this->delay == 0)
	{
		this->power = 10;
	}
}

int Human::getDirection()
{
	return this->direction;
}

void Human::setDirection(int direction)
{
	this->direction = direction;
}