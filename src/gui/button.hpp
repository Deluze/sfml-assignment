#ifndef SFMLTEST_BUTTON_HPP
#define SFMLTEST_BUTTON_HPP

#include "UIElement.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button : public UIElement, public sf::Drawable {
public:

    explicit Button() = default;

    explicit Button(sf::Text text, float width = 100, float height = 20);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool isDisabled();

    void setDisabled(const bool &disabled);

    void setText(const char *text);

    void setTextColor(const sf::Color &color);

    void setBackgroundColor(const sf::Color &color);

    void setCharacterSize(const sf::Uint32 &size);

    void onClick() override;

    void onHover() override;

private:

    // If true, this UIElement does not fire events.
    bool m_disabled = false;

    // The child text of the button
    sf::Text m_text;

    // How to do this otherwise? We need to attach children to our button, but inheriting from shapes directly makes draw method inaccessible
    sf::RectangleShape m_rectangle;

    sf::Color m_originalColor;
};

#endif //SFMLTEST_BUTTON_HPP
