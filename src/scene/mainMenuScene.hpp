#ifndef SFMLTEST_MAINMENUSCENE_HPP
#define SFMLTEST_MAINMENUSCENE_HPP

#include "scene.hpp"
#include "../game.hpp"
#include "../gui/button.hpp"

#include <functional>

#include <SFML/Graphics/Text.hpp>

class MainMenuScene : public Scene {

public:
    MainMenuScene();

    void update(Game *game) override;
    void draw(sf::RenderWindow &window) const override;
    void onEnter() override;
private:
    Button m_button;
    Button m_button2;

    sf::Text m_buttonText;
    sf::Text m_button2Text;

    void buttonClick();
};


#endif //SFMLTEST_MAINMENUSCENE_HPP
