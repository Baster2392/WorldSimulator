#include "Plant.h"

int Plant::randomNumberTo15()
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<int> distr(1, 15);

	return distr(generator);
}

bool Plant::isBreeding()
{
	if (randomNumberTo15() == 5)
	{
		return true;
	}

	return false;
}

Plant::Plant(World* world, int power, int positionX, int positionY, char icon, const char* name)
	: Organism(world, power, 0, positionX, positionY, positionX, positionY, 0, icon, name)
{

}
Plant::Plant(World* world, int power, int positionX, int positionY, int previousPositionX, int previousPositionY, int turns, char icon, const char* name)
	:Organism(world, power, 0, positionX, positionY, previousPositionX, previousPositionY, turns, icon, name)
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

bool Plant::isPlant()
{
	return true;
}
