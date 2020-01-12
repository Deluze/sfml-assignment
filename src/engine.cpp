#include "engine.hpp"
#include "scene/mainMenuScene.hpp"

Engine::Engine(const char* name) : m_name(name), m_running(false)
{

}

void Engine::initialize()
{
    m_window.create(sf::VideoMode(800, 800), m_name);
    m_sceneManager.setEngineContext(this);
}

void Engine::start()
{
    // default scene
    m_sceneManager.setScene<MainMenuScene>();

    m_running = true;

    loop();
}


void Engine::stop()
{
    m_running = false;
}

void Engine::loop()
{
    sf::Clock clock;
    sf::Uint32 lastFrame;
    constexpr sf::Uint32 timeBetweenFixedUpdated = 1000 / DELTA_TICKS;

    /**
     * Main thread loop. Used for UI/Events
     */
    while(m_running)
    {
        m_window.clear();
        m_eventManager.clear();

        EventBag* eventBag = m_eventManager.checkForEvents(m_window);

        lastFrame = clock.getElapsedTime().asMilliseconds();

        if (lastFrame >= 1000) clock.restart();

        while(lastFrame >= timeBetweenFixedUpdated)
        {
            lastFrame -= timeBetweenFixedUpdated;
            m_sceneManager.fixedUpdate(eventBag);
        }

        m_sceneManager.update(eventBag);
        m_sceneManager.draw(m_window);

        m_window.display();
    }

}

sf::RenderWindow *Engine::getWindow() {
    return &m_window;
}

SceneManager *Engine::getSceneManager() {
    return &m_sceneManager;
}
