#pragma once
#include <random>
#include <typeinfo>
#include "World.h"

class World;

class Organism
{
private:
	char icon;
	int turns;

protected:

	World* world;
	int positionX;
	int positionY;
	int prevPositionX;
	int prevPositionY;
	int power;
	int initiative;
	bool isKilled;

	virtual void breed();
	virtual bool isAttackDefended(Organism* organism);
	virtual void specialEffectAfterKilled(Organism* other);
	virtual bool hasEscaped(Organism* other);

	static const int randomFrom = 1;
	static const int randomTo = 4;

public:
	std::string name;

	// constructors and desctructors
	Organism(World* world, int power, int initiative, int positionX , int positionY, int previousPositionX, int previousPositionY, int turns, char icon, const char* name);
	~Organism();

	// main functions
	virtual void action() = 0;
	virtual void collision(Organism* other);
	virtual void goToPreviousPosition();
	virtual void goToSafeField();
	virtual bool isAnimal();
	virtual bool isPlant();

	void draw();
	void killed(Organism* killedBy);

	static void fight(Organism* organism1, Organism* organism2);

	// getters
	int getPower() const;
	int getInitiative() const;
	int getPositionX() const;
	int getPositionY() const;
	int getTurns() const;
	bool getIsKilled() const;
	std::string getName() const;

	// setters
	void setPower(int power);
	void setInitiative(int initiative);
	void setPositionX(int positionX);
	void setPositionY(int positionY);
	void setTurns(int turns);
	void setIsKilled(bool isKilled);

	friend std::ofstream& operator<<(std::ofstream& os, Organism* organism);

	// random fileds
	static int randomField();

	static const int UPPER_FIELD = 1;
	static const int LOWER_FIELD = 2;
	static const int LEFT_FIELD = 3;
	static const int RIGHT_FIELD = 4;

	static bool isSameSpecies(Organism* org1, Organism* org2);
	static bool areAtTheSamePosition(Organism* organism1, Organism* organism2);
	static bool areAtTheSamePosition(Organism* organism1, int positionX, int positionY);
};

