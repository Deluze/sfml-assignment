#ifndef SFMLTEST_SCENE_HPP
#define SFMLTEST_SCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
public:
    virtual void update(const sf::RenderWindow& renderWindow) {};
    virtual void onEnter() {};
    virtual void onLeave() {};
    virtual void onPause() {};
};

#endif //SFMLTEST_SCENE_HPP
