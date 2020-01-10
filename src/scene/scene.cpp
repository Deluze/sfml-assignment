#include "scene.hpp"
#include "../game.hpp"

#include <SFML/Window/Mouse.hpp>
#include <iostream>

void Scene::fixedUpdate(Game* game) {
}

void Scene::update(Game *game) {

    auto window = game->getWindow();

//    m_eventManager.checkForEvents(*window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && window->isOpen())
    {
        m_uiManager.resolveClick(sf::Mouse::getPosition(*window));
    }
}

void Scene::draw(sf::RenderWindow &window) const {

}

void Scene::onEnter() {

}

void Scene::onLeave() {

}

void Scene::onPause() {

}

void Scene::registerElement(UIElement *element) {
    m_uiManager.registerElement(element);
}
