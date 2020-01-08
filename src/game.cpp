#include "game.hpp"

Game::Game(const char* name) : m_name(name), m_running(false)
{

}

void Game::initialize()
{
    m_window.create(sf::VideoMode(800, 800), m_name);
    m_window.setFramerateLimit(FRAME_RATE);

    m_running = true;
}

void Game::start()
{
    loop();
}


void Game::stop()
{
    m_running = false;
}

void Game::loop()
{
    /**
     * Main thread loop. Used for UI/Events
     */
    while(m_running)
    {
        m_window.clear();

        /**
         * Do shit :P
         */

        m_window.display();
    }
}
