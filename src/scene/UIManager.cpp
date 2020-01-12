#include "UIManager.hpp"

#include <iostream>

void UIManager::registerElement(UIElement* element) {
    m_elements.push_back(element);
}

void UIManager::resolveClick(sf::Vector2i position) {
    // we use a reverse iterator here, because it could be that at some point
    // ui elements need to be rendered on top of each other
    // e.g. if there's an overlay. you would still be clicking on
    // elements underneath the overlay, we don't want that.
    for (auto it = m_elements.rbegin(); it != m_elements.rend() ; it++) {

        const auto element = *it;

        // Since these are not shapes, we have to implement our own 'contains' method.
        const auto x = static_cast<sf::Uint32>(element->getPosition().x);
        const auto y = static_cast<sf::Uint32>(element->getPosition().y);

        const auto width = static_cast<sf::Uint32>(element->getWidth());
        const auto height = static_cast<sf::Uint32>(element->getHeight());

        if (position.x >= x && position.x <= x + width)
        {
            if (position.y >= y && position.y <= y + height)
            {
                // we are not going to click on underlying elements.
                return element->onClick();
            }
        }
    }
}
