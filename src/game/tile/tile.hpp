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
    using Ptr = std::shared_ptr<Tile>;

    explicit Tile(TileType type, unsigned int x, unsigned int y);
    TileType getType();
    bool isBuildable();
    bool hasTower();
    void setTower(std::weak_ptr<Tower> tower);
    Tower::Ptr getTower();
    unsigned int getX();
    unsigned int getY();
private:
    TileType m_type;
    std::weak_ptr<Tower> m_tower;

    unsigned int m_x;
    unsigned int m_y;
};


#endif //SFMLTEST_TILE_HPP
