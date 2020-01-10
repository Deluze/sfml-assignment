#include "mainMenuScene.hpp"

void MainMenuScene::update(Game *game)
{
    m_button2.move(1, 0);

    Scene::update(game);
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

    m_button = createElement<Button>(m_buttonText);

    m_button.bindClick([this]() { m_button.setBackgroundColor(sf::Color::Magenta); });

    registerElement<Button>(m_button);

    m_button2.setBackgroundColor(sf::Color::Green);


}

void MainMenuScene::onEnter()
{

}

void MainMenuScene::buttonClick() {
    m_button.setBackgroundColor(sf::Color::Magenta);
}
