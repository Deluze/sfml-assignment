#ifndef SFMLTEST_UIMANAGER_HPP
#define SFMLTEST_UIMANAGER_HPP

#include "../gui/UIElement.hpp"

#include <vector>

#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>


class UIManager {
public:
    void registerElement(UIElement* element);

    void resolveClick(sf::Vector2i position);
private:
    std::vector<UIElement*> m_elements;
};


#endif //SFMLTEST_UIMANAGER_HPP
