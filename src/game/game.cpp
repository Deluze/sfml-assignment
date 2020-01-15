#include "game.hpp"

Game::Game() : m_health(100), m_gold(1000) {
    m_grid.initialize();
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

sf::Uint32 Game::getWave() {
    return 0;
}

Grid *Game::getGrid() {
    return &m_grid;
}
