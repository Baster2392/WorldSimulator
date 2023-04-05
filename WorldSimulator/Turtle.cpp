#include "Turtle.h"

Turtle::Turtle(World* world, int positionX, int positionY)
	:Animal(world, 2, 1, positionX, positionY, 'Z', "Zolw")
{
}

void Turtle::action()
{
	if (Organism::randomField() == 1)
	{
		move();
	}
}

bool Turtle::isAttackDefended(Organism* other)
{
	gotoxy(15, 15);
	if (other->getPower() < 5)
	{
		world->addCommunicat("Zolw odbil atal: " + other->getName());
		return true;
	}

	return false;
}
