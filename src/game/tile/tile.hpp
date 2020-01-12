#ifndef SFMLTEST_TILE_HPP
#define SFMLTEST_TILE_HPP

#include "tileType.hpp"
#include "../tower/tower.hpp"

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Tile : public sf::Drawable {
public:
    TileType getType();
    bool isBuildable();
    bool hasTower();
    void setTower(std::weak_ptr<Tower> tower);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    TileType m_type;
    std::weak_ptr<Tower> m_tower;
};


#endif //SFMLTEST_TILE_HPP
