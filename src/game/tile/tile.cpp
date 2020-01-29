#include "tile.hpp"

#include <utility>

Tile::Tile(TileType type, unsigned int x, unsigned int y) : m_type(type), m_x(x), m_y(y) {

}

TileType Tile::getType() {
    return m_type;
}

bool Tile::isBuildable() {
    return m_type != TileType::Sand;
}

bool Tile::hasTower() {
    return !m_tower.expired();
}

void Tile::setTower(std::weak_ptr<Tower> tower) {
    m_tower = std::move(tower);
}

unsigned int Tile::getX() {
    return m_x;
}

unsigned int Tile::getY() {
    return m_y;
}

Tower::Ptr Tile::getTower() {
    return m_tower.lock();
}

