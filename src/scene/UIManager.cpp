#include "UIManager.hpp"

void UIManager::registerElement(UIElement* element) {
    m_elements.push_back(element);
}

void UIManager::resolveClick(sf::Vector2i position) {
    for (auto element : m_elements)
    {
        // Since these are not shapes, we have to implement our own 'contains' method.
        const auto x = static_cast<sf::Uint32>(element->getPosition().x);
        const auto y = static_cast<sf::Uint32>(element->getPosition().y);

        auto width = static_cast<sf::Uint32>(element->getWidth());
        auto height = static_cast<sf::Uint32>(element->getHeight());

        if (position.x >= x && position.x <= x + width)
        {
            if (position.y >= y && position.y <= y + height)
            {
                element->onClick();
            }
        }
    }
}
