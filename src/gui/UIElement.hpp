#ifndef SFMLTEST_UIELEMENT_HPP
#define SFMLTEST_UIELEMENT_HPP

#include <SFML/Graphics/Shape.hpp>

class UIElement : public sf::Shape {

    using ClickHandler = std::function<void()>;
    using HoverHandler = std::function<void()>;

public:
    void bindClick(const ClickHandler& handler);
    void bindHover(const HoverHandler& handler);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual void onClick();
    virtual void onHover();
private:
    UIElement::ClickHandler m_clickHandler;
    UIElement::HoverHandler m_hoverHandler;
};

#endif //SFMLTEST_UIELEMENT_HPP
