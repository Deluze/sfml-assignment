#include "eventManager.hpp"

void EventManager::checkForEvents(sf::RenderWindow &window) {
    sf::Event theEvent{};
    while(window.pollEvent(theEvent)) {
        handleEvent(theEvent);
    }
}

void EventManager::handleEvent(sf::Event &event)
{
    auto events = m_eventHandlers[event.type];

    for(const auto& theEvent: events)
    {
        theEvent(event);
    }
}

void EventManager::subscribeTo(sf::Event::EventType eventType, std::function<void(sf::Event)> callback)
{
    auto vector = m_eventHandlers[eventType];

    vector.push_back(callback);

    m_eventHandlers[eventType][0](sf::Event{});
}