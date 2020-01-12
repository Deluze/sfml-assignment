#include "gameScene.hpp"

#include <utility>

GameScene::GameScene(std::string levelName) : Scene(), m_levelName(std::move(levelName)) {

}
