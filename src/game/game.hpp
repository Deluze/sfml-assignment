#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP

#include "grid.hpp"
#include "tower/tower.hpp"
#include "tower/towerManager.hpp"
#include "wave/waveManager.hpp"
#include "enemy/enemyManager.hpp"

#include <memory>

#include <SFML/System/Clock.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Game : public sf::Drawable, public sf::NonCopyable {
public:

    Game();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void tick();

    void addGold(sf::Uint32 amount);

    void substractGold(sf::Uint32 amount);

    void setGold(sf::Uint32 amount);

    sf::Uint32 getGold();

    void addHealth(sf::Uint32 health);

    void substractHealth(sf::Uint32 health);

    void setHealth(sf::Uint32 health);

    sf::Uint32 getHealth();

    void nextWave();

    Grid *getGrid();

    void handleTileClick(const Tile::Ptr &tile);

    bool hasTowerSelected();

    void handleEnemyPathRequest(const Enemy::Ptr& enemy);

    Tower::Ptr getSelectedTower();

    TowerManager *getTowerManager();

    WaveManager *getWaveManager();

    EnemyManager *getEnemyManager();

private:

    //Checks to see what enemies can be spawned
    void spawnEnemies();

    void spawnEnemy(const Enemy::Ptr& enemy);

    sf::Uint32 m_health;
    sf::Uint32 m_gold;

    Grid m_grid;

    TowerManager m_towerManager;
    WaveManager m_waveManager;
    EnemyManager m_enemyManager;

    Tower::Ptr m_currentSelectedTower;

    sf::Clock m_lastEnemySpawned;
};


#endif //SFMLTEST_GAME_HPP
