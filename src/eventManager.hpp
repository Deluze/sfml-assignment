#ifndef SFMLTEST_EVENTMANAGER_HPP
#define SFMLTEST_EVENTMANAGER_HPP


#include <unordered_map>
#include <vector>
#include <functional>
#include <mutex>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class EventManager {

    typedef std::unordered_map<sf::Event::EventType, std::vector<std::function<void(sf::Event)>>> EventHandlerContainer;

public:
    void checkForEvents(sf::RenderWindow& window);
    void subscribeTo(sf::Event::EventType eventType, std::function<void(sf::Event)> callback);
private:
    void handleEvent(sf::Event& event);
    EventHandlerContainer m_eventHandlers;
};

#endif //SFMLTEST_EVENTMANAGER_HPP
