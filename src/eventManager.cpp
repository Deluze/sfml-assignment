#include "eventManager.hpp"

#include <SFML/Window/Event.hpp>

EventBag* EventManager::checkForEvents(sf::RenderWindow &window) {
    sf::Event theEvent{};

    while(window.pollEvent(theEvent)) {
        m_bag.add(theEvent.type, theEvent);
    }

    return &m_bag;
}

void EventManager::clear() {
    m_bag.clear();
}