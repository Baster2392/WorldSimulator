#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h> 
#include "Organism.h"

class Organism;
class WorldInitializer;

class World
{
private:
	std::vector<std::string> communicats;
	const int positionX = 3;
	const int positionY = 4;
	int height, width;
	int numberOfOrganisms;
	int turns;

	void checkCollisions();
	void eraseCommunicats();
	void deleteKilled();
	void clearWorld();

public:
	std::vector<Organism*> organisms;

	void loadFromFile();
	World(int height, int width);
	~World();

	// main functions
	void makeTurn();
	void draw();
	void deleteOrganism(Organism* organism);
	void addOrganism(Organism* organism);
	void addCommunicat(std::string communicat);
	Organism* getOrganismAtPosition(int positionX, int positionY);
	void getSafeFieldNextTo(int positionX, int positionY, int* newPositionX, int* newPositionY);
	void printCommunicats();

	// getters
	int getPositionX();
	int getPositionY();
	int getHeight();
	int getWidth();
	int getTurns();
	int getNumbersOfOrganisms();

	friend WorldInitializer;

	static void gotoxy(int x, int y);

	// setters
	void setTurns(int turns);
};

