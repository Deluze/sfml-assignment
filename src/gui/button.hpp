#ifndef SFMLTEST_BUTTON_HPP
#define SFMLTEST_BUTTON_HPP

#include "UIElement.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>

class Button : public UIElement, public sf::Drawable {
public:

    explicit Button(const sf::Vector2f& vector, const char* text);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool isDisabled();
    void setDisabled(const bool& disabled);

    void setText(const char* text);
    void setTextColor(const sf::Color& color);
    void setBackgroundColor(const sf::Color& color);

    void onClick() override;
    void onHover() override;

private:
    bool m_disabled;
    std::string m_text;
    sf::Color m_backgroundColor;
    sf::Color m_textColor;
    sf::Vector2f m_vector;
    sf::Font m_font;
};

#endif //SFMLTEST_BUTTON_HPP
