#include <iostream>
#include "World.h"
#include "WorldInitializer.h"

class World;

int main()
{
    World world(12, 12);
    WorldInitializer init(&world);
    init.initializeWorld();
}
