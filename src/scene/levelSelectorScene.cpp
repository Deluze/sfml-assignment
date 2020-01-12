#include "levelSelectorScene.hpp"
#include "../game.hpp"
#include "mainMenuScene.hpp"

#include <filesystem>
#include <iostream>

LevelSelectorScene::LevelSelectorScene() : Scene(), m_currentSelectedLevel(0) {
    parseLevels();
}

void LevelSelectorScene::onEnter(Game *game)
{
    m_backButtonText = createElement<sf::Text>();
    m_backButtonText.setString("Back");
    m_backButtonText.setFont(m_font);
    m_backButtonText.setCharacterSize(15);

    m_backButton = createElement<Button>(m_backButtonText);
    m_backButton.setBackgroundColor(sf::Color{122, 20, 37});
    m_backButton.setPosition(0, 20);
    m_backButton.bindClick([this, game]() {onBack(game);});
    registerElement(&m_backButton);

    m_prevLevelText = createElement<sf::Text>();
    m_prevLevelText.setFont(m_font);
    m_prevLevelText.setCharacterSize(20);
    m_prevLevelText.setString("Prev level");

    m_prevLevelButton = createElement<Button>(m_prevLevelText, 100, 60);
    m_prevLevelButton.setBackgroundColor(sf::Color{130, 20, 37});
    m_prevLevelButton.setPosition(300, 400);
    m_prevLevelButton.setDisabled(!hasPrevLevel());
    m_prevLevelButton.bindClick([this]() {
        swapLevel(--m_currentSelectedLevel);
    });
    registerElement(&m_prevLevelButton);


    m_nextLevelText = createElement<sf::Text>();
    m_nextLevelText.setFont(m_font);
    m_nextLevelText.setCharacterSize(20);
    m_nextLevelText.setString("Next level");

    m_nextLevelButton = createElement<Button>(m_nextLevelText, 100, 60);
    m_nextLevelButton.setBackgroundColor(sf::Color{130, 20, 37});
    m_nextLevelButton.setPosition(410, 400);
    m_nextLevelButton.setDisabled(!hasNextLevel());
    m_nextLevelButton.bindClick([this]() {
        swapLevel(++m_currentSelectedLevel);
    });
    registerElement(&m_nextLevelButton);
}

void LevelSelectorScene::draw(sf::RenderWindow &window) const {
    window.draw(m_backButton);

    window.draw(m_prevLevelButton);
    window.draw(m_nextLevelButton);
}

void LevelSelectorScene::onBack(Game *game) {
    m_backButton.setDisabled(true);

    auto sceneManager = game->getSceneManager();
    sceneManager->setScene<MainMenuScene>();
}


void LevelSelectorScene::loadLevel(Game *game, const char* levelName)
{

}

void LevelSelectorScene::parseLevels() {
    for (const auto& directory : std::filesystem::directory_iterator(std::filesystem::relative("asset/level")))
    {
        if(std::filesystem::is_directory(directory.path()))
        {
            m_levels.push_back(directory.path().filename());
        }
    }
}

void LevelSelectorScene::swapLevel(sf::Uint32 level) {
    m_currentSelectedLevel = level;

    m_prevLevelButton.setDisabled(!hasPrevLevel());
    m_nextLevelButton.setDisabled(!hasNextLevel());
}

bool LevelSelectorScene::hasNextLevel() {
    return m_currentSelectedLevel + 1 < m_levels.size();
}

bool LevelSelectorScene::hasPrevLevel() {
    return m_currentSelectedLevel != 0;
}
