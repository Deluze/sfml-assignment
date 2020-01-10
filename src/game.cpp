#include "game.hpp"
#include "scene/mainMenuScene.hpp"

#include <iostream>

Game::Game(const char* name) : m_name(name), m_running(false)
{

}

void Game::initialize()
{
    m_window.create(sf::VideoMode(800, 800), m_name);
//    m_window.setFramerateLimit(FRAME_RATE);
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

    sf::Clock clock;
    sf::Uint32 lastFrame;

    /**
     * Main thread loop. Used for UI/Events
     */
    while(m_running)
    {
        m_window.clear();

        lastFrame = clock.getElapsedTime().asMilliseconds();

        if(lastFrame >= (1000 / DELTA_TICKS))
        {
            clock.restart();
            m_sceneManager.fixedUpdate(this);
        }

        m_sceneManager.update(this);
        m_sceneManager.draw(m_window);

        m_window.display();
    }

}

sf::RenderWindow *Game::getWindow() {
    return &m_window;
}

SceneManager *Game::getSceneManager() {
    return &m_sceneManager;
}
