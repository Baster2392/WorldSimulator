#pragma once
#include "Organism.h"

class Animal : public Organism
{
protected:
	virtual void move();

public:
	// constructors
	Animal(World* world, int power, int initiative, int positionX, int positionY, char icon, const char* name);
	Animal(World* world, int power, int initiative, int positionX, int positionY, int previousPositionX, int previousPositionY, int turns, char icon, const char* name);

	virtual void action();
	virtual void breed() = 0;
	bool isAnimal();
};

