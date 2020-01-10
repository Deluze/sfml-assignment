#ifndef SFMLTEST_SCENE_HPP
#define SFMLTEST_SCENE_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game;

class Scene
{
public:
    explicit Scene()
    {
        m_font.loadFromFile("asset/font/Arial.ttf");
    }

    virtual void update(Game* game) {};
    virtual void draw(sf::RenderWindow& window) const {};
    virtual void onEnter() {};
    virtual void onLeave() {};
    virtual void onPause() {}

protected:
    sf::Font m_font;
};

#endif //SFMLTEST_SCENE_HPP
