#include "engine.hpp"

#include <SFML/Graphics/CircleShape.hpp>

int main()
{
    auto engine = new Engine("My Engine :)");

    engine->initialize();
    engine->start();

    return 0;
}