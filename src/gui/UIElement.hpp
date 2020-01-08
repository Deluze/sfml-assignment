#ifndef SFMLTEST_UIELEMENT_HPP
#define SFMLTEST_UIELEMENT_HPP

#include <functional>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

class UIElement : public sf::Transformable {

    using ClickHandler = std::function<void()>;
    using HoverHandler = std::function<void()>;

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
