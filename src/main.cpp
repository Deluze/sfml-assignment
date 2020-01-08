#include "game.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    Game* game = new Game("My Game :)");

    game->initialize();
    game->start();

    return 0;
}