#include "Plant.h"

int Plant::randomNumberTo10()
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<int> distr(1, 10);

	return distr(generator);
}

bool Plant::isBreeding()
{
	if (randomNumberTo10() == 10)
	{
		return true;
	}

	return false;
}

Plant::Plant(World* world, int power, int positionX, int positionY, char icon, const char* name)
	: Organism(world, power, 0, positionX, positionY, icon, name)
{

}

void Plant::action()
{
	if (isBreeding())
	{
		this->breed();
	}
}

void Plant::breed()
{
}
