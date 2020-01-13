#include "grid.hpp"

//NOTE: We want to draw the tiles from left top to right bottom. This is so that towers,
// ... which don't have the height of the tile (they're a bit taller)
// will overlap each other accordingly.
void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto & row : m_tiles) {
        for (Tile* tile : row) {
            target.draw(*tile);
        }
    }
}

void Grid::setTile(sf::Uint32 row, sf::Uint32 col, Tile* tile) {
    m_tiles[row][col] = tile;
}
