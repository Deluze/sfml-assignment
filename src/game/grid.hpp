#ifndef SFMLTEST_GRID_HPP
#define SFMLTEST_GRID_HPP

#define TILE_SIZE 50
#define LEVEL_WIDTH 10
#define LEVEL_HEIGHT 10

#include "tile/tile.hpp"

#include <array>
#include <vector>
#include <cmath>
#include <unordered_map>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

class Grid : public sf::Drawable, public sf::Transformable {

    using tileContainer = std::array<std::array<Tile::Ptr, LEVEL_WIDTH>, LEVEL_HEIGHT>;
public:
    Grid();

    void initialize();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Tile::Ptr getTileFromMouse(sf::Vector2i vector);

    Tile::Ptr getTileFromPosition(sf::Vector2f vector);

    Tile::Ptr getTileFromCoordinate(sf::Vector2i vector);

    sf::Vector2f getTileWindowPosition(const Tile::Ptr &tile);

    sf::Vector2i getEnemySpawnTileCoordinate();

    sf::Vector2i getEnemyTargetTileCoordinate();

    sf::Vector2i getEnemyPathTileCoordinate(unsigned int pathIndex);

private:
    tileContainer m_tiles;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    std::vector<sf::Vector2i> m_enemyPathingPoints;
    std::unordered_map<TileType, sf::Rect<float>> m_tileTexCoords;
};


#endif //SFMLTEST_GRID_HPP
