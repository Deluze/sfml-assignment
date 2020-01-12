#ifndef SFMLTEST_MAINMENUSCENE_HPP
#define SFMLTEST_MAINMENUSCENE_HPP

#include "scene.hpp"
#include "../gui/button.hpp"

#include <functional>

#include <SFML/Graphics/Text.hpp>

class MainMenuScene : public Scene {

public:
    MainMenuScene();

    void draw(sf::RenderWindow &window) const override;
    void onEnter(Game *game) override;

private:

    sf::Text m_playButtonText;
    Button m_playButton;

    sf::Text m_quitButtonText;
    Button m_quitButton;

    void onPlay(Game* game);
    void onQuit(Game* game);
};


#endif //SFMLTEST_MAINMENUSCENE_HPP