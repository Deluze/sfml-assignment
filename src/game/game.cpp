#include "game.hpp"
#include <ctime>
#include <functional>

Game::Game() : m_health(100), m_gold(1000) {
    m_grid.initialize();
    m_towerManager.initialize();
    m_enemyManager.initialize();
}

void Game::tick() {
    m_enemyManager.tick();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // bottom layer (tiles)
    target.draw(m_grid, states);

    // enemy layer
    target.draw(m_enemyManager, states);

    // tower layer
    target.draw(m_towerManager, states);
}

void Game::addGold(sf::Uint32 amount) {
    m_gold += amount;
}

void Game::substractGold(sf::Uint32 amount) {
    if (amount > m_gold) {
        m_gold = 0;
        return;
    }

    m_gold -= amount;
}

void Game::setGold(sf::Uint32 amount) {
    m_gold = amount;
}

sf::Uint32 Game::getGold() {
    return m_gold;
}

void Game::addHealth(sf::Uint32 health) {
    m_health += health;
}

void Game::substractHealth(sf::Uint32 health) {
    if (health > m_health) {
        m_health = 0;
        return;
    }

    m_health -= health;
}

sf::Uint32 Game::getHealth() {
    return m_health;
}

void Game::setHealth(sf::Uint32 health) {
    m_health = health;
}

Grid *Game::getGrid() {
    return &m_grid;
}

void Game::handleTileClick(const Tile::Ptr &tile) {

    spawnEnemy(std::make_shared<Enemy>(100, EnemyType::GroundEnemy));

    // If it's not buildable. Means that there are no turrets on here.
    // There's nothing to do here, let's leave.
    if (!tile->isBuildable()) {
        return;
    }

    // Seems like there already is a tower built on this spot.
    // We might want to upgrade this tower.
    // Select the tower and open the upgrade
    if (tile->hasTower()) {
        m_currentSelectedTower = tile->getTower();
        return;
    }

    m_currentSelectedTower = std::make_shared<Tower>(TowerType::ElectricityTower);

    if (!tile->hasTower() && m_currentSelectedTower != nullptr) {
        tile->setTower(m_currentSelectedTower);
        m_towerManager.addTower(m_currentSelectedTower);

        // Since the tower is bigger than the actual tile. A tower equals to 70 pixels on the Y axis. Time to substract that
        // So it actually looks that the tower is on the tile.
        sf::Vector2f towerPosition = m_grid.getTileWindowPosition(tile);
        m_currentSelectedTower->setPosition(towerPosition.x, towerPosition.y - (70 - TILE_SIZE));
    }
}

bool Game::hasTowerSelected() {
    return m_currentSelectedTower != nullptr;
}

Tower::Ptr Game::getSelectedTower() {
    return m_currentSelectedTower;
}

TowerManager *Game::getTowerManager() {
    return &m_towerManager;
}

WaveManager *Game::getWaveManager() {
    return &m_waveManager;
}

void Game::nextWave() {
    m_waveManager.forceWave();
}

EnemyManager *Game::getEnemyManager() {
    return &m_enemyManager;
}

void Game::spawnEnemies() {
    // We need to check if we are eligible to spawn enemies or not.
    Wave *wave = m_waveManager.getCurrentWave();
    const unsigned int spawnInterval = wave->getEnemySpawnInterval();

    if (m_lastEnemySpawned.getElapsedTime().asMilliseconds() >= spawnInterval) {
        m_lastEnemySpawned.restart();

        // other wave will just be a regular ground enemies
        // also, we don't seed the random
        // we want our games to always be the same, right?

        EnemyType enemyType = EnemyType::GroundEnemy;

        if(m_waveManager.getCurrentWaveNo() % 3 == 0) {
            // flying wave, spawn flying enemy
            enemyType = EnemyType::AirEnemy;
        }

        if(m_waveManager.getCurrentWaveNo() % 10 == 0) {
            // boss wave, spawn random enemies, with a boss.
            // we mod it by 2, because we only have 2 enemy types (for now)
            enemyType = rand() % 2 == 0 ? EnemyType::GroundEnemy : EnemyType::AirEnemy;
        }

        // Each wave, our enemies will have 5 more health.
        spawnEnemy(std::make_shared<Enemy>(m_waveManager.getCurrentWaveNo() * 5 + 30, enemyType));
    }
}

void Game::spawnEnemy(const Enemy::Ptr& enemy) {
    m_enemyManager.addEnemy(enemy);

    const sf::Vector2i spawnLocation = m_grid.getEnemySpawnTileCoordinate();
    const Tile::Ptr tile = m_grid.getTileFromCoordinate(spawnLocation);
    const sf::Vector2f windowPosition = m_grid.getTileWindowPosition(tile);

    // we know that our enemy has a width of 35, and the tiles a width of 50.
    // 50 - 35 = 15 space left, divide that by 2, and we get a 7.5
    // BUT. Our enemy origin is in the center, meaning, that we also need to add
    // an additional 35 / 2 = 17.5 to the calculation.
    // We need to center our spawned enemy in the center of the tile.
    // And we always do these calculations relative to the top left side of the tile
    enemy->setPosition(windowPosition.x + 25.f, windowPosition.y + 25.f);
}

void Game::handleEnemyPathRequest(const Enemy::Ptr &enemy) {

}
