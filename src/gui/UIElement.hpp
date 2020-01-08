#ifndef SFMLTEST_UIELEMENT_HPP
#define SFMLTEST_UIELEMENT_HPP

#include <SFML/Graphics/Shape.hpp>
#include <memory>

class UIElement : public sf::Shape, public std::enable_shared_from_this<UIElement> {

    using Ptr = std::shared_ptr<UIElement>;
    using ClickHandler = std::function<void(UIElement::Ptr)>;
    using HoverHandler = std::function<void(UIElement::Ptr)>;

public:
    void bindClick(const ClickHandler& handler);
    void bindHover(const HoverHandler& handler);

    virtual void onClick();
    virtual void onHover();
private:
    UIElement::ClickHandler m_clickHandler;
    UIElement::HoverHandler m_hoverHandler;
};

#endif //SFMLTEST_UIELEMENT_HPP
