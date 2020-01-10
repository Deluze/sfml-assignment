#include "mainMenuScene.hpp"

void MainMenuScene::update(Game *game)
{
    m_button2.move(1, 0);
}

void MainMenuScene::draw(sf::RenderWindow &window) const {
    window.draw(m_button);
    window.draw(m_button2);
}

MainMenuScene::MainMenuScene() : Scene()
{
    m_buttonText.setFont(m_font);
    m_button2Text.setFont(m_font);

    m_buttonText.setString(":P");
    m_buttonText.setCharacterSize(10);

    m_button = Button(m_buttonText);
    m_button2 = Button(m_button2Text);

    m_button.setTextColor(sf::Color::Magenta);
    m_button.setTextColor(sf::Color::Green);
}

void MainMenuScene::onEnter()
{
}
