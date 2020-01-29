#include "scene.hpp"
#include "../engine.hpp"

#include <SFML/Window/Mouse.hpp>

void Scene::fixedUpdate(Engine *engine, EventBag *events) {
}

void Scene::update(Engine *engine, EventBag *events) {
    auto event = events->get(sf::Event::EventType::MouseButtonReleased);

    if (event == nullptr) return;
    if (event->mouseButton.button != sf::Mouse::Button::Left) return;

    m_uiManager.resolveClick({event->mouseButton.x, event->mouseButton.y});
}

void Scene::draw(sf::RenderWindow &window) const {

}

void Scene::onEnter(Engine *engine) {
}

void Scene::onLeave(Engine *engine) {
}

void Scene::onPause(Engine *engine) {
}

void Scene::registerElement(UIElement *element) {
    m_uiManager.registerElement(element);
}

void Scene::onGUI(Engine *engine) {

}
