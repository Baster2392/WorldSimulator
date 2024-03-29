#include "World.h"

World::World(int height, int width)
{
	this->height = height;
	this->width = width;
	this->numberOfOrganisms = 0;
	this->organisms;
	this->turns = 0;
}

World::~World()
{
	for (Organism* organism : this->organisms)
	{
		if (organism != nullptr)
		{
			delete organism;
		}
	}
}

void World::makeTurn()
{
	eraseCommunicats();
	this->communicats.clear();

	for (int i = 0; i < this->organisms.size(); i++)
	{
		if (!this->organisms[i]->getIsKilled())
		{
			this->organisms[i]->action();
			this->organisms[i]->setTurns(this->organisms[i]->getTurns() + 1);
		}
	}

	checkCollisions();
	deleteKilled();
	this->turns++;
}

void World::draw()
{
	gotoxy(0, 0);
	for (int i = 0; i < 2 * this->width + 2; i++)
	{
		for (int j = 0; j < this->height + 2; j++)
		{
			gotoxy(this->positionX + i - 1, this->positionY + j - 1);

			if (i == 0 || i == 2 * this->width + 1)
			{
				printf("#");
			}
			else if (j == 0 || j == this->height + 1)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
	}

	for (int i = 0; i < this->organisms.size(); i++)
	{
		gotoxy(this->positionX + organisms[i]->getPositionX() * 2, this->positionY + organisms[i]->getPositionY());
		organisms[i]->draw();
	}

	printCommunicats();

	gotoxy(0, 20);
}

void World::deleteOrganism(Organism* organism)
{
	this->organisms.erase(std::remove(organisms.begin(), organisms.end(), organism), organisms.end());
	this->numberOfOrganisms--;
}

void World::addOrganism(Organism* organism)
{
	this->numberOfOrganisms++;
	for (int i = 0; i < this->organisms.size(); i++)
	{
		if (this->organisms[i]->getInitiative() < organism->getInitiative())
		{
			organisms.insert(organisms.begin() + i, organism);
			return;
		}
	}

	organisms.push_back(organism);
}

void World::addCommunicat(std::string communicat)
{
	this->communicats.push_back(communicat);
}

void World::printCommunicats()
{
	for (int i = 0; i < this->communicats.size(); i++)
	{
		gotoxy(this->positionX + this->width + 20, i + 3);
		std::cout << communicats[i] << std::endl;
	}
}

void World::eraseCommunicats()
{
	for (int i = 0; i < this->communicats.size(); i++)
	{
		gotoxy(this->getPositionX() + this->width + 20, i + 3);
		for (int j = 0; j < 50; j++)
		{
			std::cout << " ";
		}
	}
}

void World::deleteKilled()
{
	for (Organism* organism : this->organisms)
	{
		if (organism->getIsKilled())
		{
			deleteOrganism(organism);
		}
	}
}

void World::clearWorld()
{
	numberOfOrganisms = 0;
	turns = 0;
	organisms.clear();
}

void World::loadFromFile()
{

}

Organism* World::getOrganismAtPosition(int positionX, int positionY)
{
	for (Organism* organism : this->organisms)
	{
		if (Organism::areAtTheSamePosition(organism, positionX, positionY))
		{
			return organism;
		}
	}

	return nullptr;
}

void World::getSafeFieldNextTo(int positionX, int positionY, int* newPositionX, int* newPositionY)
{
	Organism* optionalOrganism;
	if (positionX + 1 < this->width)
	{
		optionalOrganism = getOrganismAtPosition(positionX + 1, positionY);
		if (optionalOrganism == nullptr)
		{
			(*newPositionX)++;
			return;
		}
	}

	if (positionX - 1 >= 0)
	{
		optionalOrganism = getOrganismAtPosition(positionX - 1, positionY);
		if (optionalOrganism == nullptr)
		{
			(*newPositionX)--;
			return;
		}
	}

	if (positionY + 1 < this->height)
	{
		optionalOrganism = getOrganismAtPosition(positionX, positionY + 1);
		if (optionalOrganism == nullptr)
		{
			(*newPositionY)++;
			return;
		}
	}

	if (positionY - 1 >= 0)
	{
		optionalOrganism = getOrganismAtPosition(positionX, positionY - 1);
		if (optionalOrganism == nullptr)
		{
			(*newPositionY)--;
			return;
		}
	}
}

void World::checkCollisions()
{
	std::vector<Organism*> tempOrganisms = this->organisms;
	std::vector<Organism*> collision;

	for (int i = 0; i < tempOrganisms.size(); i++)
	{
		for (int j = i; j < tempOrganisms.size(); j++)
		{
			if (i == j)
			{
				continue;
			}

			if (Organism::areAtTheSamePosition(tempOrganisms[i], tempOrganisms[j]))
			{
				tempOrganisms[i]->collision(tempOrganisms[j]);
			}
		}
	}
}

int World::getPositionX()
{
	return this->positionX;
}

int World::getPositionY()
{
	return this->positionY;
}

int World::getHeight()
{
	return this->height;
}

int World::getWidth()
{
	return this->width;
}

int World::getTurns()
{
	return this->turns;
}

int World::getNumbersOfOrganisms()
{
	return this->numberOfOrganisms;
}

void World::setTurns(int turns)
{
	this->turns = turns;
}

void World::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
