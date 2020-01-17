#include "levelSelectorScene.hpp"
#include "../engine.hpp"
#include "mainMenuScene.hpp"
#include "gameScene.hpp"

LevelSelectorScene::LevelSelectorScene() : Scene(), m_currentSelectedLevel(0) {
}

void LevelSelectorScene::draw(sf::RenderWindow &window) const {
	window.draw(m_backButton);
	window.draw(m_currentSelectedLevelText);
	window.draw(m_prevLevelButton);
	window.draw(m_nextLevelButton);
	window.draw(m_playButton);
}

void LevelSelectorScene::onBack(Engine *engine) {
	auto sceneManager = engine->getSceneManager();
	sceneManager->setScene<MainMenuScene>();
}


void LevelSelectorScene::parseLevels() {
	m_levels.push_back("Test Level");
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

	if (m_currentSelectedLevel < m_levels.size()) return m_levels[m_currentSelectedLevel];

	return "No Levels Available!";
}

void LevelSelectorScene::onGUI(Engine *engine) {
	m_backButtonText.setString("Back");
	m_backButtonText.setFont(m_font);
	m_backButtonText.setCharacterSize(15);

	m_backButton = createElement<Button>(m_backButtonText);
	m_backButton.setBackgroundColor(sf::Color{ 122, 20, 37 });
	m_backButton.setPosition(0.f, 20.f);
	m_backButton.bindClick([engine]() {engine->getSceneManager()->setScene<MainMenuScene>(); });
	registerElement(&m_backButton);

	m_prevLevelText.setFont(m_font);
	m_prevLevelText.setCharacterSize(20);
	m_prevLevelText.setString("Prev level");

	m_prevLevelButton = createElement<Button>(m_prevLevelText, 100.f, 60.f);
	m_prevLevelButton.setBackgroundColor(sf::Color{ 130, 20, 37 });
	m_prevLevelButton.setPosition(300.f, 400.f);
	m_prevLevelButton.bindClick([this]() {
		swapLevel(--m_currentSelectedLevel);
	});
	registerElement(&m_prevLevelButton);

	m_nextLevelText.setFont(m_font);
	m_nextLevelText.setCharacterSize(20);
	m_nextLevelText.setString("Next level");

	m_nextLevelButton = createElement<Button>(m_nextLevelText, 100.f, 60.f);
	m_nextLevelButton.setBackgroundColor(sf::Color{ 130, 20, 37 });
	m_nextLevelButton.setPosition(410.f, 400.f);
	m_nextLevelButton.bindClick([this]() {
		swapLevel(++m_currentSelectedLevel);
	});
	registerElement(&m_nextLevelButton);

	m_currentSelectedLevelText.setFont(m_font);
	m_currentSelectedLevelText.setCharacterSize(50);
	// For now the level text will always be on the same position.
	m_currentSelectedLevelText.setString(getLevelName());
	m_currentSelectedLevelText.setPosition(300.f, 300.f);

	m_playButtonText.setFont(m_font);
	m_playButtonText.setString("Play!");

	m_playButton = createElement<Button>(m_playButtonText, 210.f, 60.f);
	m_playButton.setPosition(300.f, 480.f);
	m_playButton.setBackgroundColor(sf::Color{ 65, 161, 18 });
	m_playButton.bindClick([this, engine]() {onPlay(engine); });
	registerElement(&m_playButton);
}

void LevelSelectorScene::onEnter(Engine *engine) {
	parseLevels();

	updateBindings();
}

void LevelSelectorScene::onPlay(Engine *engine) {
	engine->getSceneManager()->setScene<GameScene>(getLevelName());
}

void LevelSelectorScene::updateBindings() {
	m_playButton.setDisabled(m_levels.empty());
	m_prevLevelButton.setDisabled(!hasPrevLevel());
	m_nextLevelButton.setDisabled(!hasNextLevel());
	m_currentSelectedLevelText.setString(getLevelName());
}
