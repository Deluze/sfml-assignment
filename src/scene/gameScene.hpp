#ifndef SFMLTEST_GAMESCENE_HPP
#define SFMLTEST_GAMESCENE_HPP

#include "scene.hpp"
#include "../game/game.hpp"

#include <string>
#include <memory>

#define STARTING_GOLD 1000
#define STARTING_HEALTH 10

class GameScene : public Scene {
public:
    explicit GameScene(std::string levelName);

    void onEnter(Engine *engine) override;
private:
    void updateBindings();

    std::string m_levelName;
    std::unique_ptr<Game> m_game;
};


#endif //SFMLTEST_GAMESCENE_HPP
