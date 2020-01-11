#include "game.hpp"

#include <SFML/Graphics/CircleShape.hpp>

int main()
{
    Game* game = new Game("My Game :)");

    game->initialize();
    game->start();

    return 0;
}