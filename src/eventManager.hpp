#ifndef SFMLTEST_EVENTMANAGER_HPP
#define SFMLTEST_EVENTMANAGER_HPP

#include "eventBag.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class EventManager {

public:
    void clear();
    EventBag* checkForEvents(sf::RenderWindow& window);
private:
    EventBag m_bag;
};

#endif //SFMLTEST_EVENTMANAGER_HPP
