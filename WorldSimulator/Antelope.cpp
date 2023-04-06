#include "Antelope.h"

void Antelope::move()
{
	this->prevPositionX = this->positionX;
	this->prevPositionY = this->positionY;

	int direction = Organism::randomField();

	if (direction == UPPER_FIELD && this->getPositionY() > 1)
	{
		this->positionY -= 2;
	}
	else if (direction == LOWER_FIELD && this->getPositionY() < world->getHeight() - 2)
	{
		this->positionY += 2;
	}
	else if (direction == RIGHT_FIELD && this->getPositionX() < world->getWidth() - 2)
	{
		this->positionX += 2;
	}
	else if (direction == LEFT_FIELD && this->getPositionX() > 1)
	{
		this->positionX -= 2;
	}
}

Antelope::Antelope(World* world, int positionX, int positionY)
	:Animal(world, 4, 4, positionX, positionY, 'A', "Antylopa")
{
}


bool Antelope::hasEscaped(Organism* organism)
{
	if (Organism::randomField() % 2 == 0)
	{
		goToSafeField();
		world->addCommunicat("Antylopa uciekla przed: " + organism->name);
		return true;
	}

	return false;
}

void Antelope::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Antelope* newAntelope = new Antelope(this->world, newPositionX, newPositionY);
	this->world->addOrganism(newAntelope);
	this->world->addCommunicat("Pojawilo sie nowe zwierze: Antylopa");
}
