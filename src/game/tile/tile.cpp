#include "tile.hpp"

#include <utility>

Tile::Tile(TileType type, unsigned int x, unsigned int y) : m_type(type), m_x(x), m_y(y){

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

void Tile::setTileType(TileType tileType) {
    m_type = tileType;
}

sf::Rect<float> Tile::getTexCoords() {
    return sf::Rect<float>(0.f, 0.f, 50.f, 50.f);
}

