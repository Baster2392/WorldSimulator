#include "Plant.h"

Plant::Plant(World* world, int power, int positionX, int positionY, char icon, const char* name)
	: Organism(world, power, 0, positionX, positionY, icon, name)
{

}

void Plant::action()
{
	if (Organism::randomField() == 1)
	{
		this->breed();
	}
}

void Plant::breed()
{
	// add plant to world
}
