#include "levelSelectorScene.hpp"
#include "../game.hpp"
#include "mainMenuScene.hpp"

#include <filesystem>

LevelSelectorScene::LevelSelectorScene() : Scene(), m_currentSelectedLevel(0) {
}

void LevelSelectorScene::draw(sf::RenderWindow &window) const {
    window.draw(m_backButton);
    window.draw(m_currentSelectedLevelText);
    window.draw(m_prevLevelButton);
    window.draw(m_nextLevelButton);
    window.draw(m_playButton);
}

void LevelSelectorScene::onBack(Game *game) {
    auto sceneManager = game->getSceneManager();
    sceneManager->setScene<MainMenuScene>();
}


void LevelSelectorScene::parseLevels() {

    std::string path = std::filesystem::relative("asset/level");

    if(!std::filesystem::exists(path)) return;

    for (const auto& directory : std::filesystem::directory_iterator(path))
    {
        if(std::filesystem::is_directory(directory.path()))
        {
            m_levels.push_back(directory.path().filename());
        }
    }
}

void LevelSelectorScene::swapLevel(sf::Uint32 level) {
    m_currentSelectedLevel = level;

    updateBindings();
}

bool LevelSelectorScene::hasNextLevel() {
    return m_currentSelectedLevel + 1 < m_levels.size();
}

bool LevelSelectorScene::hasPrevLevel() {
    return m_currentSelectedLevel != 0;
}

std::string LevelSelectorScene::getLevelName() {

    if(m_currentSelectedLevel < m_levels.size()) return m_levels[m_currentSelectedLevel];

    return "No Levels Available!";
}

void LevelSelectorScene::onGUI(Game *game) {
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
    m_nextLevelButton.bindClick([this]() {
        swapLevel(++m_currentSelectedLevel);
    });
    registerElement(&m_nextLevelButton);

    m_currentSelectedLevelText = createElement<sf::Text>();
    m_currentSelectedLevelText.setFont(m_font);
    m_currentSelectedLevelText.setCharacterSize(50);
    // For now the level text will always be on the same position.
    m_currentSelectedLevelText.setString(getLevelName());
    m_currentSelectedLevelText.setPosition(300, 300);

    m_playButtonText = createElement<sf::Text>();
    m_playButtonText.setFont(m_font);
    m_playButtonText.setString("Play!");

    m_playButton = createElement<Button>(m_playButtonText, 210, 60);
    m_playButton.setPosition(300, 480);
    m_playButton.setBackgroundColor(sf::Color{65, 161, 18});
    m_playButton.bindClick([this, game]() {onPlay(game); });
}

void LevelSelectorScene::onEnter(Game *game) {
    parseLevels();

    updateBindings();
}

void LevelSelectorScene::onPlay(Game *game) {

}

void LevelSelectorScene::updateBindings() {
    m_playButton.setDisabled(m_levels.empty());
    m_prevLevelButton.setDisabled(!hasPrevLevel());
    m_nextLevelButton.setDisabled(!hasNextLevel());
    m_currentSelectedLevelText.setString(getLevelName());
}
