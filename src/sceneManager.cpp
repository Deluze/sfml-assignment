#include "sceneManager.hpp"

void SceneManager::update(Game *game) {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->update(game);
}

void SceneManager::draw(sf::RenderWindow& window) const {
    m_scene->draw(window);
}

void SceneManager::fixedUpdate(Game* game) {
    m_scene->fixedUpdate(game);
}
