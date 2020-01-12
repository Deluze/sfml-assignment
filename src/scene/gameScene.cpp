#include "gameScene.hpp"

#include <utility>

GameScene::GameScene(std::string levelName) : Scene(), m_levelName(std::move(levelName)) {

}

void GameScene::onEnter(Engine *engine) {
    m_game = std::make_unique<Game>();
}

void GameScene::updateBindings() {

}
