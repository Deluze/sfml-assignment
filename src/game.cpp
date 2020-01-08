#include "game.hpp"
#include "gui/button.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Game::Game(const char* name) : m_name(name), m_running(false)
{

}

void Game::initialize()
{
    m_window.create(sf::VideoMode(800, 800), m_name);
    m_window.setFramerateLimit(FRAME_RATE);
}

void Game::start()
{
    m_running = true;

    loop();
}


void Game::stop()
{
    m_running = false;
}

void Game::loop()
{

    Button button{{100, 20}, "Hello"};

    button.setBackgroundColor(sf::Color::Green);
    button.setTextColor(sf::Color::White);

    /**
     * Main thread loop. Used for UI/Events
     */
    while(m_running)
    {
        m_window.clear();

        m_window.draw(button);
        /**
         * Do shit :P
         */

        m_window.display();
    }
}
