#ifndef SFMLTEST_GAMESCENE_HPP
#define SFMLTEST_GAMESCENE_HPP

#include "scene.hpp"
#include "../game/game.hpp"
#include "../gui/button.hpp"
#include "../engine.hpp"

#include <string>
#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>

class GameScene : public Scene {
public:
    explicit GameScene(std::string levelName);

    void onEnter(Engine *engine) override;
    void onGUI(Engine *engine) override;
    void draw(sf::RenderWindow &window) const override;
private:
    void updateBindings();

    sf::Text m_waveText;
    sf::Text m_healthText;
    sf::Text m_goldText;
    sf::Text m_exitText;
    sf::Text m_levelText;

    sf::Sprite m_goldSprite;
    sf::Texture m_goldTexture;

    sf::Sprite m_healthSprite;
    sf::Texture m_healthTexture;

    sf::RectangleShape m_header;
    sf::RectangleShape m_footer;

    Button m_exitButton;

    std::string m_levelName;
    std::unique_ptr<Game> m_game;
};


#endif //SFMLTEST_GAMESCENE_HPP
