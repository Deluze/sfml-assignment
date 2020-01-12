#ifndef SFMLTEST_GRID_HPP
#define SFMLTEST_GRID_HPP

#include "tile/tile.hpp"

#include <array>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Grid : public sf::Drawable {

    using tileContainer = std::array<std::array<Tile*, 100>, 100>;
public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setTile(sf::Uint32 row, sf::Uint32 col, Tile* tile);
private:
    tileContainer m_tiles;
};


#endif //SFMLTEST_GRID_HPP
