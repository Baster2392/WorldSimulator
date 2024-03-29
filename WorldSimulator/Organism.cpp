#include "Organism.h"

int Organism::randomField()
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distr(randomFrom, randomTo);

    return distr(generator);
}

bool Organism::isSameSpecies(Organism* org1, Organism* org2)
{
    if (org1->getName() == org2->getName())
    {
        return true;
    }

    return false;
}

bool Organism::areAtTheSamePosition(Organism* organism1, Organism* organism2)
{
	return organism1->getPositionX() == organism2->getPositionX() &&
		organism1->getPositionY() == organism2->getPositionY();
}

bool Organism::areAtTheSamePosition(Organism* organism1, int positionX, int positionY)
{
	return organism1->getPositionX() == positionX &&
		organism1->getPositionY() == positionY;
}

Organism::Organism(World* world, int power, int initiative, int positionX, int positionY, int previousPositionX, int previousPositionY, int turns, char icon, const char* name)
{
	this->world = world;
	this->power = power;
	this->initiative = initiative;
	this->positionX = positionX;
	this->positionY = positionY;
	this->turns = turns;
	this->icon = icon;
	this->isKilled = false;
	this->name = name;
	this->prevPositionX = previousPositionX;
	this->prevPositionY = previousPositionY;
}

Organism::~Organism()
{
	
}

void Organism::collision(Organism* other)
{
	if (isSameSpecies(this, other))
	{
		this->breed();
	}
	else
	{
		fight(this, other);
	}
}

void Organism::breed()
{

}

bool Organism::isAttackDefended(Organism* organism)
{
	return false;
}

void Organism::specialEffectAfterKilled(Organism* other)
{
}

bool Organism::hasEscaped(Organism* organism)
{
	return false;
}

void Organism::goToPreviousPosition()
{
	this->positionX = this->prevPositionX;
	this->positionY = this->prevPositionY;
}

void Organism::goToSafeField()
{
	this->prevPositionX = this->positionX;
	this->prevPositionY = this->positionY;

	if (this->world->getOrganismAtPosition(this->positionX + 1, this->positionX) == nullptr
		&& this->positionX + 1 < world->getWidth() - 1)
	{
		this->positionX++;
	}
	else if (this->world->getOrganismAtPosition(this->positionY + 1, this->positionY) == nullptr
		&& this->positionY + 1 < world->getHeight() - 1)
	{
		this->positionY++;
	}
	else if (this->world->getOrganismAtPosition(this->positionX + 1, this->positionX) == nullptr
		&& this->positionX - 1 > 0)
	{
		this->positionX--;
	}
	else if (this->world->getOrganismAtPosition(this->positionY + 1, this->positionY) == nullptr
		&& this->positionY - 1 > 0)
	{
		this->positionY--;
	}
}

bool Organism::isAnimal()
{
	return false;
}

bool Organism::isPlant()
{
	return false;
}

void Organism::draw()
{
	printf("%c", icon);
}

void Organism::killed(Organism* killedBy)
{
	this->specialEffectAfterKilled(killedBy);

	std::string com = this->name + " zabity przez: " + killedBy->name;
	world->addCommunicat(com);

	this->isKilled = true;
	//this->world->deleteOrganism(this);
}

void Organism::fight(Organism* organism1, Organism* organism2)
{
	if (organism1->hasEscaped(organism2) || organism2->hasEscaped(organism1))
	{
		return;
	}

	if (organism1->isAttackDefended(organism2))
	{
		organism2->goToPreviousPosition();
		return;
	}
	else if (organism2->isAttackDefended(organism1))
	{
		organism1->goToPreviousPosition();
		return;
	}

	if (organism1->getInitiative() > organism2->getInitiative())
	{
		if (organism1->getPower() >= organism2->getPower())
		{
			organism2->killed(organism1);
		}
		else
		{
			organism1->killed(organism2);
		}
	}
	else if (organism1->getInitiative() < organism2->getInitiative())
	{
		if (organism2->getPower() >= organism1->getPower())
		{
			organism1->killed(organism2);
		}
		else
		{
			organism2->killed(organism1);
		}
	}
	else if (organism1->getTurns() > organism2->getTurns())
	{
		if (organism1->getPower() >= organism2->getPower())
		{
			organism2->killed(organism1);
		}
		else
		{
			organism1->killed(organism2);
		}
	}
	else if (organism1->getTurns() < organism2->getTurns())
	{
		if (organism2->getPower() >= organism1->getPower())
		{
			organism1->killed(organism2);
		}
		else
		{
			organism2->killed(organism1);
		}
	}
	else
	{
		if (organism1->getPower() >= organism2->getPower())
		{
			organism2->killed(organism1);
		}
		else
		{
			organism1->killed(organism2);
		}
	}
}

int Organism::getPower() const
{
    return this->power;
}

int Organism::getInitiative() const
{
    return this->initiative;
}

int Organism::getPositionX() const
{
    return this->positionX;
}

int Organism::getPositionY() const
{
    return this->positionY;
}

int Organism::getTurns() const
{
	return this->turns;
}

bool Organism::getIsKilled() const
{
	return this->isKilled;
}

std::string Organism::getName() const
{
	return this->name;
}

void Organism::setPower(int power)
{
    this->power = power;
}

void Organism::setInitiative(int initiative)
{
    this->initiative = initiative;
}

void Organism::setPositionX(int positionX)
{
    this->positionX = positionX;
}

void Organism::setPositionY(int positionY)
{
    this->positionY = positionY;
}

void Organism::setTurns(int turns)
{
	this->turns = turns;
}

void Organism::setIsKilled(bool isKilled)
{
	this->isKilled = isKilled;
}

std::ofstream& operator<<(std::ofstream& os, Organism* organism)
{
	os << organism->name << std::endl;
	os << organism->positionX << std::endl;
	os << organism->positionY << std::endl;
	os << organism->prevPositionX << std::endl;
	os << organism->prevPositionY << std::endl;
	os << organism->power << std::endl;
	os << organism->initiative << std::endl;
	os << organism->turns;

	return os;
}
