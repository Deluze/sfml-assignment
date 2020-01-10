#ifndef SFMLTEST_SCENEMANAGER_HPP
#define SFMLTEST_SCENEMANAGER_HPP

#include "scene/scene.hpp"
#include "scene/exception/noSceneSetException.hpp"
#include "loopable.hpp"

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

class Game;

class SceneManager {
public:
    template<class SceneClass, class ...Args>
    void setScene(Args... args)
    {
       if(m_scene != nullptr) {
           m_scene->onLeave();
       }

        m_scene.reset();
        m_scene = std::make_unique<SceneClass>(args...);
        m_scene->onEnter();
    }

    void update(Game* game);
    void draw(sf::RenderWindow& window) const;
private:
    std::unique_ptr<Scene> m_scene;
};

#endif //SFMLTEST_SCENEMANAGER_HPP
