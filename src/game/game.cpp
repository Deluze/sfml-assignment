#include "game.hpp"

Game::Game() : m_health(100), m_gold(1000) {
    m_grid.initialize();
    m_towerManager.initialize();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // bottom layer (tiles)
    target.draw(m_grid, states);

    // enemy layer

    // tower layer
    target.draw(m_towerManager, states);
}

void Game::addGold(sf::Uint32 amount) {
    m_gold += amount;
}

void Game::substractGold(sf::Uint32 amount) {
    if(amount > m_gold) {
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
    if(health > m_health)
    {
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

void Game::handleTileClick(const Tile::Ptr& tile) {

    // If it's not buildable. Means that there are no turrets on here.
    // There's nothing to do here, let's leave.
    if(!tile->isBuildable()) {
        return;
    }

    // Seems like there already is a tower built on this spot.
    // We might want to upgrade this tower.
    // Select the tower and open the upgrade
    if(tile->hasTower()) {
        m_currentSelectedTower = tile->getTower();
        return;
    }

    m_currentSelectedTower = std::make_shared<Tower>(TowerType::Fire);

    if(!tile->hasTower() && m_currentSelectedTower != nullptr) {
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
