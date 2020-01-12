#include "sceneManager.hpp"

void SceneManager::update(EventBag* events) {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->update(m_game, events);
}

void SceneManager::draw(sf::RenderWindow& window) const {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->draw(window);
}

void SceneManager::fixedUpdate(EventBag* events) {
    if(m_scene == nullptr) {
        throw NoSceneSetException();
    }

    m_scene->fixedUpdate(m_game, events);
}

void SceneManager::setGameContext(Engine *game) {
    m_game = game;
}
