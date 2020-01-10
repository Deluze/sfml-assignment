#ifndef SFMLTEST_SCENE_HPP
#define SFMLTEST_SCENE_HPP

#include "UIManager.hpp"
#include "../eventManager.hpp"
#include "../gui/UIElement.hpp"

#include <functional>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Game;

class Scene
{
public:
    explicit Scene()
    {
        m_font.loadFromFile("asset/font/Arial.ttf");
    }

    // This method is always called 60 times a second.
    virtual void fixedUpdate(Game* game);

    // This method should always be called, if inherited. Since this will listen to events and UI states.
    virtual void update(Game* game);

    // Callback for making drawings to the screen.
    virtual void draw(sf::RenderWindow& window) const;

    // Callback before an actual update or draw loop will happen.
    virtual void onEnter();

    // Callback just before this scene will get destroyed by the manager.
    virtual void onLeave();

    // Callback whenever the window loses focus or user presses a button.
    virtual void onPause();

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
    EventManager m_eventManager;
protected:
    sf::Font m_font;
};

#endif //SFMLTEST_SCENE_HPP
