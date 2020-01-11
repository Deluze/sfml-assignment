#ifndef SFMLTEST_EVENTBAG_HPP
#define SFMLTEST_EVENTBAG_HPP

#include <SFML/Window/Event.hpp>

#include <unordered_map>

class EventBag {
public:
    void add(sf::Event::EventType eventType, sf::Event theEvent);
    bool has(sf::Event::EventType eventType);
    sf::Event* get(sf::Event::EventType eventType);
    void clear();
private:
    std::unordered_map<sf::Event::EventType, sf::Event> m_events;
};


#endif //SFMLTEST_EVENTBAG_HPP
