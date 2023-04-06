#include <iostream>
#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"

int main()
{
    int turns = 0;
    char ch;
    World world(7, 7);
    Human human(&world, 0, 0);
    Wolf wolf(&world, 3, 3);
    Wolf wolf2(&world, 4, 4);
    Wolf wolf3(&world, 2, 2);
    Sheep sheep(&world, 5, 4);
    Fox fox(&world, 6, 6);
    Turtle turtle(&world, 3, 1);
    Antelope antelope(&world, 2, 2);
    Grass grass(&world, 1, 5);

    world.addOrganism(&human);
    world.addOrganism(&wolf);
    world.addOrganism(&wolf2);
    world.addOrganism(&fox);
    world.addOrganism(&turtle);
    world.addOrganism(&antelope);
    world.addOrganism(&sheep);
    world.addOrganism(&grass);

    world.draw();

    while (ch = getch())
    {
        switch (ch)
        {
        case 'w':
            human.setDirection(Organism::UPPER_FIELD);
            break;
        case 's':
            human.setDirection(Organism::LOWER_FIELD);
            break;
        case 'a':
            human.setDirection(Organism::LEFT_FIELD);
            break;
        case 'd':
            human.setDirection(Organism::RIGHT_FIELD);
            break;
        case 'u':
            human.specialAbility();
            break;

        default:
            world.makeTurn();
            world.draw();
            turns++;
        }

        gotoxy(1, 1);
        printf("Turns: %d Power: %d ", turns, human.getPower());
    }
}
