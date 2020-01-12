#include "grid.hpp"

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
