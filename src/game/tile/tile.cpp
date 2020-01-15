#include "tile.hpp"

#include <utility>


Tile::Tile(TileType tileType) : m_type(tileType) {

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
