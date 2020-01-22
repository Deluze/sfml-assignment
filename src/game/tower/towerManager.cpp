#include "towerManager.hpp"

void TowerManager::addTower(const Tower::Ptr& tower) {
    tower->setTexture(m_towersTexture, m_towerTexCoords[tower->getTowerType()]);
    m_towers.push_back(tower);
}

void TowerManager::removeTower(const Tower::Ptr& tower) {
    m_towers.erase(std::find(m_towers.begin(), m_towers.end(), tower));
}

void TowerManager::initialize() {
    m_towerTexCoords[TowerType::Gun] = {0,0,50,70};
    m_towerTexCoords[TowerType::Bow] = {50,0,50,70};
    m_towerTexCoords[TowerType::Ice] = {100,0,50,70};
    m_towerTexCoords[TowerType::Poison] = {150,0,50,70};
    m_towerTexCoords[TowerType::Fire] = {0,70,50,70};
    m_towerTexCoords[TowerType::Bomb] = {50,70,50,70};
    m_towerTexCoords[TowerType::Dark] = {100,70,50,70};
    m_towerTexCoords[TowerType::Electricity] = {150,70,50,70};

    m_towersTexture.loadFromFile("asset/texture/towers.png");
}

void TowerManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const auto& tower : m_towers)
    {
        target.draw(*tower, states);
    }
}
