#include "button.hpp"

#include <utility>

Button::Button(sf::Text text, float width, float height) : UIElement({width, height}), m_disabled(false), m_text(std::move(text))
{
    m_rectangle = sf::RectangleShape({
        width, height
    });

    m_text.setPosition((width - m_text.getGlobalBounds().width) / 2, (height - m_text.getGlobalBounds().height) / 2 - 3);
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

void Button::setCharacterSize(const sf::Uint32& size) {
    m_text.setCharacterSize(size);
}