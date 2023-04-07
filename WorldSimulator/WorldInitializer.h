#pragma once
#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "PineBorscht.h"

class WorldInitializer
{
private:
	World* world;
	Human* human;

	void saveToFile();
	void loadFromFile();
public:
	WorldInitializer(World* world);
	void initializeWorld();
	void buildOrganism(World* world, const char* name, int positionX, int positionY, int prevPositionX, int prevPositionY, int power, int initiative, int turns);
};

