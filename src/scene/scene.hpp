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

    virtual void update(Game* game);
    virtual void draw(sf::RenderWindow& window) const;
    virtual void onEnter();
    virtual void onLeave();
    virtual void onPause();

    template<class T, class ...Args>
    T createElement(Args... args)
    {
        return T(args...);
    }

    template<class T>
    void registerElement(T& element)
    {
        m_uiManager.registerElement(element);
    }

private:
    UIManager m_uiManager;
    EventManager m_eventManager;
protected:
    sf::Font m_font;
};

#endif //SFMLTEST_SCENE_HPP
