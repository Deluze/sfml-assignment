#ifndef SFMLTEST_EVENTMANAGER_HPP
#define SFMLTEST_EVENTMANAGER_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include <mutex>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class eventManager {

    typedef std::unordered_map<sf::Event::EventType, std::vector<std::function<void(sf::Event)>>> EventHandlerContainer;

public:
    void checkForEvents(sf::RenderWindow& window);
    void subscribeTo(sf::Event::EventType eventType, const std::function<void(sf::Event)>& callback);
private:
    void handleEvent(sf::Event& event);
    EventHandlerContainer m_eventHandlers;
    std::mutex m_eventMutex;
};

#endif //SFMLTEST_EVENTMANAGER_HPP
