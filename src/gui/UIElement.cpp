#include "UIElement.hpp"

#include "exception/cantBeDrawnException.hpp"

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
