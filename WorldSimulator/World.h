#pragma once
#include <iostream>
#include "Organism.h"
#include "conio2.h"

class Organism;

class World
{
private:
	std::vector<std::string> communicats;
	const int positionX = 3;
	const int positionY = 3;
	int height, width;

protected:
	std::vector<Organism*> organisms;
	int numberOfOrganisms;

	void checkCollisions();
	void printCommunicats();
	void eraseCommunicats();

public:
	World(int height, int width);

	// main functions
	void makeTurn();
	void draw();
	void deleteOrganism(Organism* organism);
	void addOrganism(Organism* organism);
	void addCommunicat(std::string communicat);
	Organism* getOrganismAtPosition(int positionX, int positionY);

	// getters
	int getPositionX();
	int getPositionY();
	int getHeight();
	int getWidth();
};

