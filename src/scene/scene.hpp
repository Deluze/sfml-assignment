#ifndef SFMLTEST_SCENE_HPP
#define SFMLTEST_SCENE_HPP

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

    virtual void update(Game* game)
    {
        // handle events
    };
    virtual void draw(sf::RenderWindow& window) const {};
    virtual void onEnter() {};
    virtual void onLeave() {};
    virtual void onPause() {};

    template<class Element, class ...Args>
    Element createElement(Args... args)
    {
        return Element(args...);
    }

private:
    std::vector<sf::Transformable*> m_transformables;
protected:
    sf::Font m_font;
};

#endif //SFMLTEST_SCENE_HPP
