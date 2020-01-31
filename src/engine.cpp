#include "engine.hpp"
#include "scene/mainMenuScene.hpp"

Engine::Engine(const char *name) : m_name(name), m_running(false) {

}

void Engine::initialize() {
    m_window.create(sf::VideoMode(800, 800), m_name, sf::Style::Titlebar | sf::Style::Close);

    // we set a frame limit, just in case. Seems like SFML doesn't have a standard cap
    // and we don't want to use all of our GPU power.
    m_window.setFramerateLimit(144);

    m_sceneManager.setEngineContext(this);
}

void Engine::start() {
    // default scene
    m_sceneManager.setScene<MainMenuScene>();

    m_running = true;

    startLoop();
}


void Engine::stop() {
    m_running = false;
}

void Engine::startLoop() {
    sf::Clock clock;
    unsigned int lastFrame;
    unsigned int catchedUpFrames{0};
    constexpr unsigned int timeBetweenFixedUpdated = 1000 / DELTA_TICKS;

    /**
     * Main thread startLoop. Used for UI/Events
     */
    while (m_running) {
        //Engine logic
        m_eventManager.clear();
        EventBag *eventBag = m_eventManager.checkForEvents(m_window);

        lastFrame = clock.getElapsedTime().asMilliseconds();

        //Game logic
        while (lastFrame - catchedUpFrames > timeBetweenFixedUpdated) {
            catchedUpFrames += timeBetweenFixedUpdated;
            m_sceneManager.fixedUpdate(eventBag);
        }

        m_sceneManager.update(eventBag);

        //Render
        m_window.clear();
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
