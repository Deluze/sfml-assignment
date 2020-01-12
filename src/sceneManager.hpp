#ifndef SFMLTEST_SCENEMANAGER_HPP
#define SFMLTEST_SCENEMANAGER_HPP

#include "scene/scene.hpp"
#include "scene/exception/noSceneSetException.hpp"
#include "eventBag.hpp"

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

class Engine;

class SceneManager {
public:
    template<class SceneClass, class ...Args>
    void setScene(Args... args)
    {
       if(m_scene != nullptr) {
           m_scene->onLeave(m_game);
       }

        m_scene.reset();
        m_scene = std::make_unique<SceneClass>(args...);
        m_scene->onGUI(m_game);
        m_scene->onEnter(m_game);
    }

    void fixedUpdate(EventBag* events);
    void update(EventBag* event);
    void draw(sf::RenderWindow& window) const;
    void setEngineContext(Engine* game);
private:
    std::unique_ptr<Scene> m_scene;
    Engine* m_game;
};

#endif //SFMLTEST_SCENEMANAGER_HPP
