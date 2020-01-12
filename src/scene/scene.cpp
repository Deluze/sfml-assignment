#include "scene.hpp"
#include "../game.hpp"

#include <SFML/Window/Mouse.hpp>

void Scene::fixedUpdate(Game* game, EventBag* events) {
}

void Scene::update(Game *game, EventBag* events)
{
    auto window = game->getWindow();

    auto event = events->get(sf::Event::EventType::MouseButtonReleased);

    if(event == nullptr) return;
    if(event->mouseButton.button != sf::Mouse::Button::Left) return;

    m_uiManager.resolveClick({
        event->mouseButton.x,
        event->mouseButton.y
    });
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