#ifndef SFMLTEST_LEVELSELECTORSCENE_HPP
#define SFMLTEST_LEVELSELECTORSCENE_HPP

#include "scene.hpp"
#include "../gui/button.hpp"

#include <vector>

class LevelSelectorScene : public Scene {
public:
    LevelSelectorScene();
    void onEnter(Engine *engine) override;
    void onGUI(Engine *engine) override;
    void draw(sf::RenderWindow &window) const override;
private:
    void parseLevels();
    void swapLevel(sf::Uint32 level);
    bool hasNextLevel();
    bool hasPrevLevel();
    std::string getLevelName();
    void updateBindings();

    sf::Text m_backButtonText;
    Button m_backButton;

    sf::Text m_prevLevelText;
    Button m_prevLevelButton;

    sf::Text m_nextLevelText;
    Button m_nextLevelButton;

    sf::Text m_currentSelectedLevelText;

    sf::Text m_playButtonText;
    Button m_playButton;

    std::vector<std::string> m_levels;
    sf::Uint32 m_currentSelectedLevel;
};


#endif //SFMLTEST_LEVELSELECTORSCENE_HPP
