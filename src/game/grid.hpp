#ifndef SFMLTEST_GRID_HPP
#define SFMLTEST_GRID_HPP

#define TILE_SIZE 50
#define LEVEL_WIDTH 10
#define LEVEL_HEIGHT 10

#include "tile/tile.hpp"
#include "direction.hpp"

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

    Tile::Ptr getTileFromMouse(sf::Vector2<int> vector) const;

    Tile::Ptr getTileFromPosition(sf::Vector2<float> vector) const;

    Tile::Ptr getTileFromCoordinate(sf::Vector2<int> vector) const;

    sf::Vector2<float> getTileWindowPosition(const Tile::Ptr &tile) const;

    sf::Vector2<int> getEnemySpawnTileCoordinate() const;

    sf::Vector2<int> getEnemyTargetTileCoordinate() const;

    sf::Vector2<int> getEnemyPathTileCoordinate(unsigned int pathIndex) const;

    sf::Vector2<float> getTileWindowPositionFromTileCoordinate(sf::Vector2<int> coordinate) const;

    Direction determineDirection(sf::Vector2<float> currentPosition, sf::Vector2<float> targetPosition) const;

private:
    tileContainer m_tiles;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    std::vector<sf::Vector2<int>> m_enemyPathingPoints;
    std::unordered_map<TileType, sf::Rect<float>> m_tileTexCoords;
};


#endif //SFMLTEST_GRID_HPP
