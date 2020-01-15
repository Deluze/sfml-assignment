#ifndef SFMLTEST_TILE_HPP
#define SFMLTEST_TILE_HPP

#include "tileType.hpp"
#include "../tower/tower.hpp"

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Tile {
public:
    explicit Tile(TileType tileType = TileType::Grass);
    TileType getType();
    bool isBuildable();
    bool hasTower();
    void setTower(std::weak_ptr<Tower> tower);
    void setTileType(TileType tileType);
private:
    TileType m_type;
    std::weak_ptr<Tower> m_tower;
};


#endif //SFMLTEST_TILE_HPP
