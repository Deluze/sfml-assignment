#ifndef SFMLTEST_GAMESCENE_HPP
#define SFMLTEST_GAMESCENE_HPP

#include "scene.hpp"
#include "../game/game.hpp"
#include "../gui/button.hpp"
#include "../engine.hpp"
#include "../gui/game/shopItem.hpp"

#include <string>
#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>

class GameScene : public Scene {
public:
    explicit GameScene(std::string levelName);

    void fixedUpdate(Engine *engine, EventBag *events) override;

    void update(Engine *engine, EventBag *events) override;

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
    sf::Text m_nextWaveText;
    sf::Text m_remainingTimeUntilNextWaveText;
    sf::Text m_remainingEnemiesCountText;

    sf::Sprite m_groundSprite;
    sf::Texture m_groundTexture;

    sf::Sprite m_goldSprite;
    sf::Texture m_goldTexture;

    sf::Sprite m_healthSprite;
    sf::Texture m_healthTexture;

    sf::RectangleShape m_header;
    sf::RectangleShape m_footer;

    Button m_exitButton;

    Button m_nextWaveButton;

    std::string m_levelName;

    Game m_game;

    // separated for shop
    ShopItem m_electricTowerItem;
    sf::Text m_electricTowerName;
    sf::Text m_electricTowerGoldText;

    ShopItem m_bombTowerItem;
    sf::Text m_bombTowerName;
    sf::Text m_bombTowerGoldText;
};


#endif //SFMLTEST_GAMESCENE_HPP
