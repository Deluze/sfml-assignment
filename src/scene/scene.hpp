#ifndef SFMLTEST_SCENE_HPP
#define SFMLTEST_SCENE_HPP

#include "UIManager.hpp"
#include "../gui/UIElement.hpp"
#include "../eventBag.hpp"

#include <functional>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Game;

class Scene
{
    using event = sf::Event;

public:
    explicit Scene()
    {
        m_font.loadFromFile("asset/font/Arial.ttf");
    }

    // This method is always called 60 times a second.
    virtual void fixedUpdate(Game* game, EventBag* events);

    // This method should always be called, if inherited. Since this will listen to events and UI states.
    virtual void update(Game* game, EventBag* events);

    // Callback for making drawings to the screen.
    virtual void draw(sf::RenderWindow& window) const;

    // Callback before an actual update or draw loop will happen.
    virtual void onEnter(Game* game);

    // Callback just before this scene will get destroyed by the manager.
    virtual void onLeave(Game* game);

    // Callback whenever the window loses focus or user presses a button.
    virtual void onPause(Game* game);

    // This is just a fancy, totally unnecessary ctor
    // But it is used to make instantiating UI elements look standard.
    template<class T, class ...Args>
    T createElement(Args... args)
    {
        return T(args...);
    }

    // Registers
    void registerElement(UIElement* element);

private:
    UIManager m_uiManager;
protected:
    sf::Font m_font;
};

#endif //SFMLTEST_SCENE_HPP
