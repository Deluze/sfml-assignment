#include "game.hpp"
#include "gui/button.hpp"
#include "scene/mainMenuScene.hpp"

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
    // default scene
    m_sceneManager.setScene<MainMenuScene>();

    m_running = true;

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

        m_sceneManager.update(this);
        m_sceneManager.draw(m_window);

        m_window.display();
    }

}

sf::RenderWindow *Game::getWindow() {
    return &m_window;
}
