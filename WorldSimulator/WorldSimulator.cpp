#include <iostream>
#include "World.h"
#include "WorldInitializer.h"

class World;

int main()
{
    World world(14, 14);
    WorldInitializer init(&world);
    init.initializeWorld();
}
