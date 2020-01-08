#include "UIElement.hpp"

void UIElement::bindClick(const UIElement::ClickHandler &handler)
{
    m_clickHandler = handler;
}

void UIElement::bindHover(const UIElement::HoverHandler &handler)
{
    m_hoverHandler = handler;
}

void UIElement::onClick() {
    m_clickHandler(shared_from_this());
}

void UIElement::onHover() {
    m_hoverHandler(shared_from_this());
}
