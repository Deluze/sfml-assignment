#include "gameScene.hpp"
#include "levelSelectorScene.hpp"

#include <utility>
#include <sstream>

GameScene::GameScene(std::string levelName) : Scene(), m_levelName(std::move(levelName)), m_game(std::make_unique<Game>()) {

}

void GameScene::update(Engine *engine, EventBag *events) {

    if(events->has(sf::Event::EventType::MouseButtonReleased)) {
        auto event = events->get(sf::Event::EventType::MouseButtonReleased);
        if(event->mouseButton.button == sf::Mouse::Button::Left) {
            auto tile = m_game->getGrid()->getTileFromMouse({event->mouseButton.x, event->mouseButton.y});
            if (tile != nullptr)
            {
                events->take(sf::Event::EventType::MouseButtonReleased); // we found a tile, no need to look for any other GUI clicks.
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
    waveText << "Wave: " << std::to_string(m_game->getWave());
    m_waveText.setString(waveText.str());

    m_healthText.setString(std::to_string(m_game->getHealth()));
    m_goldText.setString(std::to_string(m_game->getGold()));
    m_levelText.setString(m_levelName);
}

void GameScene::onGUI(Engine *engine) {

    m_game->getGrid()->setPosition(150, 150);

    m_waveText.setFont(m_font);
    m_healthText.setFont(m_font);
    m_goldText.setFont(m_font);
    m_exitText.setFont(m_font);
    m_levelText.setFont(m_font);
    m_healthTexture.loadFromFile("asset/sprite/heart.png");
    m_healthSprite.setTexture(m_healthTexture);
    m_goldTexture.loadFromFile("asset/sprite/gold.png");
    m_goldSprite.setTexture(m_goldTexture);
    m_exitText.setString("Exit");

    m_header.setSize({800, 40});
    m_header.setFillColor(sf::Color{255, 255, 255, 50});

    m_footer.setSize({800, 120});
    m_footer.setFillColor(sf::Color{255, 255, 255, 50});
    m_footer.setPosition({0, 800 - m_footer.getSize().y});

    m_healthSprite.setPosition(600, 10);
    m_healthText.setPosition(630, 10);
    m_healthText.setCharacterSize(15);

    m_goldSprite.setPosition(450, 10);
    m_goldText.setPosition(480, 10);
    m_goldText.setCharacterSize(15);

    m_waveText.setPosition(700, 10);
    m_waveText.setCharacterSize(15);

    m_levelText.setPosition(150, 10);
    m_levelText.setCharacterSize(15);

    m_exitButton = createElement<Button>(m_exitText, 100, 40);
    m_exitButton.setPosition(0, 0);
    m_exitButton.bindClick( [engine](){ engine->getSceneManager()->setScene<LevelSelectorScene>(); });
    m_exitButton.setBackgroundColor(sf::Color{255, 0, 0, 128});
    registerElement(&m_exitButton);
}

void GameScene::draw(sf::RenderWindow &window) const {
    window.draw(m_header);
    window.draw(m_footer);
    window.draw(m_levelText);
    window.draw(m_waveText);
    window.draw(m_goldText);
    window.draw(m_healthText);
    window.draw(m_healthSprite);
    window.draw(m_goldSprite);
    window.draw(m_exitButton);
    window.draw(*m_game->getGrid());
}
