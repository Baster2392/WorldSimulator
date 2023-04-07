#include "Turtle.h"

Turtle::Turtle(World* world, int positionX, int positionY)
	:Animal(world, 2, 1, positionX, positionY, 'Z', "Zolw")
{
}

Turtle::Turtle(World* world, int positionX, int positionY, int previousPositionX, int previousPositionY, int power, int initiative, int turns)
	:Animal(world, power, initiative, positionX, positionY, previousPositionX, previousPositionY, turns, 'Z', "Zolw")
{
}

void Turtle::action()
{
	if (Organism::randomField() == 1)
	{
		move();
	}
}

void Turtle::breed()
{
	int newPositionX = this->positionX;
	int newPositionY = this->positionY;

	world->getSafeFieldNextTo(this->positionX, this->positionY, &newPositionX, &newPositionY);

	if (this->positionX == newPositionX && this->positionY == newPositionY)
	{
		return;
	}

	Turtle* newTurtle = new Turtle(this->world, newPositionX, newPositionY);
	this->world->addOrganism(newTurtle);
	this->world->addCommunicat("Pojawilo sie nowe zwierze: Zolw");
}

bool Turtle::isAttackDefended(Organism* other)
{
	gotoxy(15, 15);
	if (other->getPower() < 5)
	{
		world->addCommunicat("Zolw odbil atak: " + other->getName());
		return true;
	}

	return false;
}
