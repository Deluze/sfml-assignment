#ifndef SFMLTEST_SCENE_HPP
#define SFMLTEST_SCENE_HPP

#include "UIManager.hpp"
#include "../gui/UIElement.hpp"
#include "../eventBag.hpp"

#include <functional>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Engine;

class Scene
{
public:
    explicit Scene()
    {
		// This is the generic font being used in every scene.
        m_font.loadFromFile("asset/font/Arial.ttf");
    }

    // This method is always called 60 times a second.
    virtual void fixedUpdate(Engine* engine, EventBag* events);

    // This method should always be called, if inherited. Since this will listen to events and UI states.
    virtual void update(Engine* engine, EventBag* events);

    // Callback for making drawings to the screen.
    virtual void draw(sf::RenderWindow& window) const;

    // Callback before an actual update or draw loop will happen.
    virtual void onEnter(Engine* engine);

    // Callback just before this scene will get destroyed by the manager.
    virtual void onLeave(Engine* engine);

    // Callback whenever the window loses focus or user presses a button.
    virtual void onPause(Engine* engine);

    // Callback used for setting up the UI, gets called before `onEnter`
    virtual void onGUI(Engine* engine);

    // This is just a fancy, totally unnecessary ctor
    // But it is used to make instantiating UI elements look standard.
    template<class T, class ...Args>
    T createElement(Args... args)
    {
        return T(args...);
    }

    // Registers the element to the UI manager. So it can handle basic click events.
    void registerElement(UIElement* element);
private:
    using event = sf::Event;
    using eventType = event::EventType;

    UIManager m_uiManager;
protected:
    sf::Font m_font;
};

#endif //SFMLTEST_SCENE_HPP
