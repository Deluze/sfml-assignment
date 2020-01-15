#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP

#include "grid.hpp"
#include "tower/tower.hpp"

#include <memory>

#include <SFML/Config.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Game : public sf::Drawable, public sf::NonCopyable {
public:
    Game();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addGold(sf::Uint32 amount);
    void substractGold(sf::Uint32 amount);
    void setGold(sf::Uint32 amount);
    sf::Uint32 getGold();

    void addHealth(sf::Uint32 health);
    void substractHealth(sf::Uint32 health);
    void setHealth(sf::Uint32 health);
    sf::Uint32 getHealth();

    sf::Uint32 getWave();

    Grid* getGrid();

    void handleTileClick(Tile* tile);
    Tile* getSelectedTile();

    bool hasTowerSelected();
    Tower::Ptr getSelectedTower();
private:

    sf::Uint32 m_health;
    sf::Uint32 m_gold;

    Grid m_grid;

    Tile* m_currentSelectedTile;
    Tower::Ptr m_currentSelectedTower;
    std::vector<Tower::Ptr> m_towers;
};


#endif //SFMLTEST_GAME_HPP
