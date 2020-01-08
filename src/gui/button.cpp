#include "button.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

Button::Button(const sf::Vector2f& vector, const char* text) : Drawable(), m_vector(vector), m_text(text), m_disabled(false)
{
    m_font.loadFromFile("asset/font/Arial.ttf");
}

void Button::setDisabled(const bool &disabled) {
    m_disabled = disabled;
}

bool Button::isDisabled() {
    return m_disabled;
}

void Button::onClick() {
    if (m_disabled) {
        return;
    }

    UIElement::onClick();
}

void Button::onHover() {
    if (m_disabled) {
        return;
    }

    UIElement::onHover();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    sf::RectangleShape base{m_vector};
    sf::Text text{m_text, m_font};

    base.setFillColor(m_backgroundColor);

    if (m_disabled) {
        base.setFillColor(sf::Color{150, 150, 150});
    }

    text.setFillColor(m_textColor);

    target.draw(base);
    target.draw(text);
}

void Button::setText(const char *text) {
    m_text = text;
}

void Button::setBackgroundColor(const sf::Color &color) {
    m_backgroundColor = color;
}

void Button::setTextColor(const sf::Color &color) {
    m_textColor = color;
}
