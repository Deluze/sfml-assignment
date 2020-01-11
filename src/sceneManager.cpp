#include "sceneManager.hpp"

void SceneManager::update() {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->update(m_game);
}

void SceneManager::draw(sf::RenderWindow& window) const {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->draw(window);
}

void SceneManager::fixedUpdate() {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->fixedUpdate(m_game);
}

void SceneManager::setGameContext(Game *game) {
    m_game = game;
}
