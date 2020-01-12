#ifndef SFMLTEST_GAMESCENE_HPP
#define SFMLTEST_GAMESCENE_HPP

#include "scene.hpp"

#include <string>

class GameScene : public Scene {
public:
    explicit GameScene(std::string levelName);
private:
    std::string m_levelName;
};


#endif //SFMLTEST_GAMESCENE_HPP
