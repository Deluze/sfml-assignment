#ifndef SFMLTEST_GRID_HPP
#define SFMLTEST_GRID_HPP

#define TILE_SIZE 50
#define LEVEL_WIDTH 10
#define LEVEL_HEIGHT 10

#include "tile/tile.hpp"

#include <array>
#include <cmath>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

class Grid : public sf::Drawable, public sf::Transformable {

    using tileContainer = std::array<std::array<Tile, LEVEL_WIDTH>, LEVEL_HEIGHT>;
public:
    Grid();
    void initialize();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    Tile* getTileFromMouse(sf::Vector2i vector);
    Tile* getTileFromPosition(sf::Vector2f vector);
private:
    tileContainer m_tiles;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#endif //SFMLTEST_GRID_HPP
