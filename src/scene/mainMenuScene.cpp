#include "mainMenuScene.hpp"

#include "../engine.hpp"
#include "levelSelectorScene.hpp"

MainMenuScene::MainMenuScene() : Scene() {

}

void MainMenuScene::draw(sf::RenderWindow &window) const {
    window.draw(m_playButton);
    window.draw(m_quitButton);
}

void MainMenuScene::onGUI(Engine *engine) {
    m_playButtonText.setFont(m_font);
    m_playButtonText.setString("Play!");

    m_playButton = createElement<Button>(m_playButtonText, 200.f, 50.f);
    m_playButton.setBackgroundColor(sf::Color{214, 47, 75});
    m_playButton.setPosition(0.f, 100.f);
    m_playButton.bindClick([engine]() { engine->getSceneManager()->setScene<LevelSelectorScene>(); });

    registerElement(&m_playButton);

    m_quitButtonText.setFont(m_font);
    m_quitButtonText.setString("Quit");
    m_quitButtonText.setCharacterSize(15);

    m_quitButton = createElement<Button>(m_quitButtonText, 150.f, 20.f);
    m_quitButton.setBackgroundColor(sf::Color{122, 20, 37});
    m_quitButton.setPosition(0.f, 175.f);
    m_quitButton.bindClick([engine]() { engine->getWindow()->close(); });

    registerElement(&m_quitButton);
}
