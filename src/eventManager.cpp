#include "eventManager.hpp"

void eventManager::checkForEvents(sf::RenderWindow &window) {
    sf::Event theEvent{};
    while(window.pollEvent(theEvent)) {
        handleEvent(theEvent);
    }
}

void eventManager::handleEvent(sf::Event &event)
{
    std::lock_guard<std::mutex> lg(m_eventMutex);

    auto events = m_eventHandlers.at(event.type);

    for(const auto& theEvent: events)
    {
        theEvent(event);
    }
}

void eventManager::subscribeTo(sf::Event::EventType eventType, const std::function<void(sf::Event)>& callback)
{
    std::lock_guard<std::mutex> lg(m_eventMutex);

    auto vector = m_eventHandlers.at(eventType);

    vector.push_back(callback);
}
