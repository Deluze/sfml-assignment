#include "scene.hpp"
#include "../game.hpp"

#include <SFML/Window/Mouse.hpp>
#include <iostream>

void Scene::fixedUpdate(Game* game, EventBag* events) {
}

void Scene::update(Game *game, EventBag* events)
{
    auto window = game->getWindow();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && window->isOpen())
    {
        m_uiManager.resolveClick(sf::Mouse::getPosition(*window));
    }
}

void Scene::draw(sf::RenderWindow &window) const {

}

void Scene::onEnter(Game* game) {
}

void Scene::onLeave(Game* game) {
}

void Scene::onPause(Game* game) {
}

void Scene::registerElement(UIElement *element) {
    m_uiManager.registerElement(element);
}
