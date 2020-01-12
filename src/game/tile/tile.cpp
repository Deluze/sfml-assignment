#include "tile.hpp"

TileType Tile::getType() {
    return m_type;
}

bool Tile::isBuildable() {
    return m_type != TileType::Pathway;
}

bool Tile::hasTower() {
    return !m_tower.expired();
}

void Tile::setTower(std::weak_ptr<Tower> tower) {
    m_tower = tower;
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
