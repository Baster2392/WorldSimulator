#include <iostream>
#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

int main()
{
    int turns = 0;
    char ch;
    World world(6, 6);
    Human human(&world, 0, 0);
    Wolf wolf(&world, 3, 3);
    Sheep sheep(&world, 5, 4);
    Fox fox(&world, 4, 4);
    Turtle turtle(&world, 3, 1);
    Antelope antelope(&world, 2, 2);

    world.addOrganism(&human);
    world.addOrganism(&wolf);
    world.addOrganism(&sheep);
    world.addOrganism(&fox);
    world.addOrganism(&turtle);
    world.addOrganism(&antelope);

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
            world.deleteOrganism(&human);
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
