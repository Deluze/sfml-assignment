#include "button.hpp"

Button::Button(sf::RectangleShape rectangleShape, const char* text) : UIElement(), m_rectangle(rectangleShape), m_disabled(false)
{
    m_font.loadFromFile("asset/font/Arial.ttf");
    m_text.setFont(m_font);
    m_text.setString(text);
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
    states.transform = getTransform();

    target.draw(m_rectangle, states);
    target.draw(m_text, states);
}

void Button::setText(const char *text) {
    m_text.setString(text);
}

void Button::setBackgroundColor(const sf::Color &color) {
    m_rectangle.setFillColor(color);
}

void Button::setTextColor(const sf::Color &color) {
    m_text.setFillColor(color);
}
