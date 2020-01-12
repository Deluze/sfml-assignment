#include "mainMenuScene.hpp"

#include "../game.hpp"
#include "levelSelectorScene.hpp"

MainMenuScene::MainMenuScene() : Scene()
{

}

void MainMenuScene::draw(sf::RenderWindow &window) const
{
    window.draw(m_playButton);
    window.draw(m_quitButton);
}

void MainMenuScene::onPlay(Game* game) {
    m_playButton.setDisabled(true);

    const auto sceneManager = game->getSceneManager();
    sceneManager->setScene<LevelSelectorScene>();
}

void MainMenuScene::onQuit(Game* game) {
    m_quitButton.setDisabled(true);

    game->getWindow()->close();
}

void MainMenuScene::onEnter(Game *game) {
    m_playButtonText = createElement<sf::Text>();
    m_playButtonText.setFont(m_font);
    m_playButtonText.setString("Play!");

    m_playButton = createElement<Button>(m_playButtonText, 200, 50);
    m_playButton.setBackgroundColor(sf::Color{214, 47, 75});
    m_playButton.setPosition(0, 100);
    m_playButton.bindClick([this, game]() {onPlay(game);});

    registerElement(&m_playButton);

    m_quitButtonText = createElement<sf::Text>();
    m_quitButtonText.setFont(m_font);
    m_quitButtonText.setString("Quit");
    m_quitButtonText.setCharacterSize(15);

    m_quitButton = createElement<Button>(m_quitButtonText, 150, 20);
    m_quitButton.setBackgroundColor(sf::Color{122, 20, 37});
    m_quitButton.setPosition(0, 175);
    m_quitButton.bindClick([this, game]() {onQuit(game);});

    registerElement(&m_quitButton);
}
