#include "mainMenuScene.hpp"

MainMenuScene::MainMenuScene() : Scene()
{
    m_playButtonText = createElement<sf::Text>();
    m_playButtonText.setFont(m_font);
    m_playButtonText.setString("Play!");

    m_playButton = createElement<Button>(m_playButtonText, 200, 50);
    m_playButton.setBackgroundColor(sf::Color{214, 47, 75});
    m_playButton.setPosition(0, 100);
    m_playButton.bindClick([this]() {onPlay();});

    registerElement(&m_playButton);

    m_quitButtonText = createElement<sf::Text>();
    m_quitButtonText.setFont(m_font);
    m_quitButtonText.setString("Quit");
    m_quitButtonText.setCharacterSize(15);

    m_quitButton = createElement<Button>(m_quitButtonText, 150, 20);
    m_quitButton.setBackgroundColor(sf::Color{122, 20, 37});
    m_quitButton.setPosition(0, 175);
    m_quitButton.bindClick([this]() {onQuit();});

    registerElement(&m_quitButton);
}

void MainMenuScene::draw(sf::RenderWindow &window) const
{
    window.draw(m_playButton);
    window.draw(m_quitButton);
}

void MainMenuScene::onPlay() {

}

void MainMenuScene::onQuit() {

}
