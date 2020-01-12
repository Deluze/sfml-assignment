#ifndef SFMLTEST_ENGINE_HPP
#define SFMLTEST_ENGINE_HPP

#include "sceneManager.hpp"
#include "eventManager.hpp"

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#define DELTA_TICKS 60

class Engine {
public:
    explicit Engine(const char* name);
    ~Engine() = default;

    void initialize();
    void start();
    void stop();

    sf::RenderWindow* getWindow();
    SceneManager* getSceneManager();
private:

    void loop();

    sf::RenderWindow m_window;
    std::string m_name;
    SceneManager m_sceneManager;
    EventManager m_eventManager;
    bool m_running;
};

#endif //SFMLTEST_ENGINE_HPP
