#include "UIElement.hpp"

#include "exception/cantBeDrawnException.hpp"

UIElement::UIElement(sf::Vector2f vector) {
    m_vector = vector;
}

void UIElement::bindClick(const UIElement::ClickHandler &handler)
{
    m_clickHandler = handler;
}

void UIElement::bindHover(const UIElement::HoverHandler &handler)
{
    m_hoverHandler = handler;
}

void UIElement::onClick()
{
    m_clickHandler();
}

void UIElement::onHover()
{
    m_hoverHandler();
}

float UIElement::getWidth()
{
    return m_vector.x;
}

float UIElement::getHeight()
{
    return m_vector.y;
}

void UIElement::setWidth(float width)
{
    m_vector.x = width;
}

void UIElement::setHeight(float height)
{
    m_vector.y = height;
}
