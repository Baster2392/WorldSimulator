#include "WorldInitializer.h"

void WorldInitializer::saveToFile()
{
	std::ofstream saveFile("save/save.txt");
	saveFile << world->turns << std::endl;
	saveFile << world->numberOfOrganisms << std::endl;
	saveFile << this->human->getBoost() << std::endl;
	saveFile << this->human->getDelay() << std::endl;

	for (Organism* organism : this->world->organisms)
	{
		saveFile << organism << std::endl << std::endl;
	}

	saveFile.close();

	this->world->addCommunicat("Zapisano stan swiata");
	this->world->printCommunicats();
}

void WorldInitializer::loadFromFile()
{
	this->world->clearWorld();

	std::ifstream loadFile("save/save.txt");
	std::string line;

	std::getline(loadFile, line);
	this->world->turns = atoi(line.c_str());

	std::getline(loadFile, line);
	int numberOfOrganisms = atoi(line.c_str());

	std::getline(loadFile, line);
	int boost = atoi(line.c_str());

	std::getline(loadFile, line);
	int delay = atoi(line.c_str());

	std::string name;
	int posX, posY, prevPosX, prevPosY, power, initiative, turns;
	for (int i = 0; i < numberOfOrganisms; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::getline(loadFile, line);
			switch (j)
			{
			case 0:
				name = line;
				std::replace(name.begin(), name.end(), '\n', '\0');
				break;
			case 1:
				posX = atoi(line.c_str());
				break;
			case 2:
				posY = atoi(line.c_str());
				break;
			case 3:
				prevPosX = atoi(line.c_str());
				break;
			case 4:
				prevPosY = atoi(line.c_str());
				break;
			case 5:
				power = atoi(line.c_str());
				break;
			case 6:
				initiative = atoi(line.c_str());
				break;
			case 7:
				turns = atoi(line.c_str());
				break;
			}
		}

		if (name == "Czlowiek")
		{
			if (this->human != nullptr)
			{
				delete human;
			}

			this->human = new Human(this->world, posX, posY, prevPosX, prevPosY, power, initiative, turns, boost, delay);
			this->world->addOrganism(this->human);
			continue;
		}

		buildOrganism(this->world, name.c_str(), posX, posY, prevPosX, prevPosY, power, initiative, turns);
	}

	loadFile.close();
	this->world->draw();
	this->world->addCommunicat("Zaladowano stan swiata");
	//this->world->addCommunicat("Liczba organizmow: " + std::to_string(this->world->numberOfOrganisms));
	this->world->printCommunicats();
}

WorldInitializer::WorldInitializer(World* world)
{
	this->world = world;
}

void WorldInitializer::initializeWorld()
{
	this->human = new Human(world, 0, 0);
	Wolf* wolf = new Wolf(world, 3, 3);
	Wolf* wolf2 = new Wolf(world, 4, 4);
	Wolf* wolf3 = new Wolf(world, 2, 2);
	Sheep* sheep = new Sheep(world, 5, 4);
	Sheep* sheep2 = new Sheep(world, 5, 6);
	Fox* fox = new Fox(world, 6, 6);
	Turtle* turtle = new Turtle(world, 3, 1);
	Antelope* antelope = new Antelope(world, 2, 2);
	Grass* grass = new Grass(world, 1, 5);
	Dandelion* dandelion = new Dandelion(world, 9, 9);
	Guarana* guarana = new Guarana(world, 7, 7);
	Guarana* guarana2 = new Guarana(world, 7, 9);
	Nightshade* nightshade = new Nightshade(world, 2, 3);
	PineBorscht* pineBorsvht = new PineBorscht(world, 2, 7);

	world->addOrganism(this->human);
	world->addOrganism(wolf);
	world->addOrganism(wolf2);
	world->addOrganism(fox);
	world->addOrganism(turtle);
	world->addOrganism(antelope);
	world->addOrganism(sheep);
	world->addOrganism(sheep2);
	world->addOrganism(grass);
	world->addOrganism(dandelion);
	world->addOrganism(guarana);
	world->addOrganism(guarana2);
	world->addOrganism(nightshade);
	world->addOrganism(pineBorsvht);

	world->draw();
	gotoxy(1, 1);
	printf("Jakub Slawinski 193271");

	char ch;
	int turns = 0;

	while (true)
	{
		ch = getch();
		switch (ch)
		{
		case 'H':
			human->setDirection(Organism::UPPER_FIELD);
			break;
		case 'P':
			human->setDirection(Organism::LOWER_FIELD);
			break;
		case 'K':
			human->setDirection(Organism::LEFT_FIELD);
			break;
		case 'M':
			human->setDirection(Organism::RIGHT_FIELD);
			break;
		case 'q':
			return;
		case 'u':
			human->specialAbility();
			break;
		case 's':
			saveToFile();
			break;
		case 'l':
			loadFromFile();
			break;

		case ' ':
			this->world->makeTurn();
			this->world->draw();
		}

		gotoxy(1, 2);
		printf("Turns: %d Power: %d ", this->world->getTurns(), this->human->getPower());
	}
}

void WorldInitializer::buildOrganism(World* world, const char* name, int positionX, int positionY, int prevPositionX, int prevPositionY, int power, int initiative, int turns)
{
	std::string str = name;
	Organism* newOrganism = nullptr;
	if (str == "Antylopa")
	{
		newOrganism = new Antelope(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Mlecz")
	{
		newOrganism = new Dandelion(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Lis")
	{
		newOrganism = new Fox(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Trawa")
	{
		newOrganism = new Grass(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Guarana")
	{
		newOrganism = new Guarana(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Wilcze jagody")
	{
		newOrganism = new Nightshade(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Barszcz sosnowskiego")
	{
		newOrganism = new PineBorscht(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Owca")
	{
		newOrganism = new Sheep(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Zolw")
	{
		newOrganism = new Turtle(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}
	else if (str == "Wilk")
	{
		newOrganism = new Wolf(world, positionX, positionY, prevPositionX, prevPositionY, power, initiative, turns);
	}

	this->world->addOrganism(newOrganism);
}
