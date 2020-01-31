#include "gameScene.hpp"
#include "levelSelectorScene.hpp"

#include <utility>
#include <sstream>

GameScene::GameScene(std::string levelName)
        : Scene(), m_levelName(std::move(levelName)) {

}

void GameScene::fixedUpdate(Engine *engine, EventBag *events) {
    m_game.tick();

    if (m_game.getWaveManager()->getWaveCooldown() == 0) {
        m_game.nextWave();
    }

    updateBindings();
}

void GameScene::update(Engine *engine, EventBag *events) {

    if (events->has(sf::Event::EventType::MouseButtonReleased)) {
        auto event = events->get(sf::Event::EventType::MouseButtonReleased);
        if (event->mouseButton.button == sf::Mouse::Button::Left) {
            auto tile = m_game.getGrid()->getTileFromMouse({event->mouseButton.x, event->mouseButton.y});
            if (tile != nullptr) {
                // we found a tile, no need to look for any other GUI clicks.
                events->take(sf::Event::EventType::MouseButtonReleased);
                m_game.handleTileClick(tile);
            } else {
                if (m_game.hasTowerSelected()) {
                    m_game.deselectTower();
                }
            }
        }
    }

    Scene::update(engine, events);
}

void GameScene::onEnter(Engine *engine) {

    updateBindings();
}

void GameScene::updateBindings() {

    std::ostringstream waveText;
    waveText << "Wave: " << std::to_string(m_game.getWaveManager()->getCurrentWaveNo());
    m_waveText.setString(waveText.str());

    m_healthText.setString(std::to_string(m_game.getHealth()));
    m_goldText.setString(std::to_string(m_game.getGold()));
    m_levelText.setString(m_levelName);

    const unsigned int coolDown = m_game.getWaveManager()->getWaveCooldown();

    m_remainingTimeUntilNextWaveText.setFillColor(sf::Color::White);

    if (coolDown <= 10) {
        if (coolDown % 2 == 0) {
            m_remainingTimeUntilNextWaveText.setFillColor(sf::Color::Red);
        }
    }

    const bool enemiesPresent = m_game.getEnemyManager()->getEnemyCount() > 0;
    m_nextWaveButton.setDisabled(enemiesPresent);
    m_nextWaveButton.setBackgroundColor(sf::Color{0, 125, 125, static_cast<sf::Uint8>(enemiesPresent ? 32 : 255)});

    m_remainingTimeUntilNextWaveText.setString(std::to_string(m_game.getWaveManager()->getWaveCooldown()));
    m_remainingEnemiesCountText.setString(std::to_string(m_game.getEnemyManager()->getEnemyCount()));
}

void GameScene::onGUI(Engine *engine) {

    m_game.getGrid()->setPosition(150, 150);

    m_waveText.setFont(m_font);
    m_healthText.setFont(m_font);
    m_goldText.setFont(m_font);
    m_exitText.setFont(m_font);
    m_levelText.setFont(m_font);
    m_nextWaveText.setFont(m_font);
    m_remainingTimeUntilNextWaveText.setFont(m_font);
    m_remainingEnemiesCountText.setFont(m_font);
    m_electricTowerName.setFont(m_font);
    m_electricTowerGoldText.setFont(m_font);
    m_bombTowerGoldText.setFont(m_font);
    m_bombTowerName.setFont(m_font);

    m_healthTexture.loadFromFile("asset/sprite/heart.png");
    m_healthSprite.setTexture(m_healthTexture);
    m_goldTexture.loadFromFile("asset/sprite/gold.png");
    m_goldSprite.setTexture(m_goldTexture);

    m_exitText.setString("Exit");
    m_nextWaveText.setCharacterSize(17);
    m_nextWaveText.setString("Next wave");

    m_header.setSize({800.f, 40.f});
    m_header.setFillColor(sf::Color{255, 255, 255, 50});

    m_footer.setSize({800.f, 120.f});
    m_footer.setFillColor(sf::Color{255, 255, 255, 50});
    m_footer.setPosition({0.f, 800.f - m_footer.getSize().y});

    m_healthSprite.setPosition(400.f, 10.f);
    m_healthText.setPosition(425.f, 10.f);
    m_healthText.setCharacterSize(15);

    m_goldSprite.setPosition(250.f, 10.f);
    m_goldText.setPosition(275.f, 10.f);
    m_goldText.setCharacterSize(15);

    m_waveText.setPosition(500.f, 10.f);
    m_waveText.setCharacterSize(15);

    m_exitButton = createElement<Button>(m_exitText, 100.f, 40.f);
    m_exitButton.setPosition(0.f, 0.f);
    m_exitButton.bindClick([engine]() { engine->getSceneManager()->setScene<LevelSelectorScene>(); });
    m_exitButton.setBackgroundColor(sf::Color{255, 0, 0, 128});
    registerElement(&m_exitButton);

    m_nextWaveButton = createElement<Button>(m_nextWaveText, 100.f, 40.f);
    m_nextWaveButton.setPosition(700.f, 0.f);
    m_nextWaveButton.bindClick([this]() { m_game.nextWave(); });
    registerElement(&m_nextWaveButton);

    m_remainingTimeUntilNextWaveText.setPosition(675.f, 10.f);
    m_remainingTimeUntilNextWaveText.setCharacterSize(13);

    m_remainingEnemiesCountText.setCharacterSize(13);
    m_remainingEnemiesCountText.setPosition(600.f, 10.f);


    // ------ shop ------

    m_electricTowerName.setString("Electric");
    m_electricTowerGoldText.setString("100");

    m_electricTowerItem = createElement<ShopItem>(TowerType::ElectricityTower, m_electricTowerName, m_electricTowerGoldText);
    m_electricTowerItem.setPosition(0.f, 680.f);
    m_electricTowerItem.bindClick([this](){
        m_game.selectTower(m_electricTowerItem.getTower());
    });
    registerElement(&m_electricTowerItem);

    m_bombTowerName.setString("Bomb");
    m_bombTowerGoldText.setString("100");

    m_bombTowerItem = createElement<ShopItem>(TowerType::BombTower, m_bombTowerName, m_bombTowerGoldText);
    m_bombTowerItem.setPosition(120.f, 680.f);
    m_bombTowerItem.bindClick([this]() {
        m_game.selectTower(m_bombTowerItem.getTower());
    });
    registerElement(&m_bombTowerItem);
}

void GameScene::draw(sf::RenderWindow &window) const {
    window.draw(m_header);
    window.draw(m_footer);
    window.draw(m_waveText);
    window.draw(m_goldText);
    window.draw(m_healthText);
    window.draw(m_healthSprite);
    window.draw(m_goldSprite);
    window.draw(m_exitButton);
    window.draw(m_remainingTimeUntilNextWaveText);
    window.draw(m_remainingEnemiesCountText);
    window.draw(m_nextWaveButton);
    window.draw(m_electricTowerItem);
    window.draw(m_bombTowerItem);
    window.draw(m_game);
}
