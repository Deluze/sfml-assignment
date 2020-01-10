#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP

#include "sceneManager.hpp"

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#define DELTA_TICKS 60

class Game {
public:
    explicit Game(const char* name);
    ~Game() = default;

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
    bool m_running;
};

#endif //SFMLTEST_GAME_HPP
