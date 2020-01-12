#ifndef SFMLTEST_LEVELSELECTORSCENE_HPP
#define SFMLTEST_LEVELSELECTORSCENE_HPP

#include "scene.hpp"
#include "../gui/button.hpp"
#include "../game/level.hpp"

#include <vector>

class LevelSelectorScene : public Scene {
public:
    LevelSelectorScene();
    void onEnter(Game *game) override;
    void draw(sf::RenderWindow &window) const override;
private:
    void loadLevel(Game* game, const char* levelName);
    void onBack(Game* game);
    void parseLevels();
    void swapLevel(sf::Uint32 level);
    bool hasNextLevel();
    bool hasPrevLevel();

    sf::Text m_backButtonText;
    Button m_backButton;

    sf::Text m_prevLevelText;
    Button m_prevLevelButton;

    sf::Text m_nextLevelText;
    Button m_nextLevelButton;

    std::vector<std::string> m_levels;
    sf::Uint32 m_currentSelectedLevel;
};


#endif //SFMLTEST_LEVELSELECTORSCENE_HPP
