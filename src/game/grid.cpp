#include "grid.hpp"

#include <cmath>

Grid::Grid() : m_vertices(sf::VertexArray{sf::PrimitiveType::Quads, LEVEL_HEIGHT * LEVEL_WIDTH * 4}) {
    m_tileset.loadFromFile("asset/texture/tileset.png");
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &m_tileset;

    target.draw(m_vertices, states);
}

void Grid::initialize() {
    m_tileTexCoords[TileType::Grass] = sf::Rect<float>(0.f, 0.f, 50.f, 50.f);
    m_tileTexCoords[TileType::Sand] = sf::Rect<float>(50.f, 0.f, 50.f, 50.f);

    // This is the level grid.. for now
    // until the level selector is build.
    unsigned int level[LEVEL_WIDTH][LEVEL_HEIGHT] = {
            {0, 1, 0, 0, 1, 1, 1, 1, 1, 1},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    };

    m_enemyPathingPoints.emplace_back(1, 0);
    m_enemyPathingPoints.emplace_back(1, 2);
    m_enemyPathingPoints.emplace_back(5, 2);
    m_enemyPathingPoints.emplace_back(5, 5);
    m_enemyPathingPoints.emplace_back(1, 5);
    m_enemyPathingPoints.emplace_back(1, 8);
    m_enemyPathingPoints.emplace_back(4, 8);
    m_enemyPathingPoints.emplace_back(4, 9);
    m_enemyPathingPoints.emplace_back(8, 9);
    m_enemyPathingPoints.emplace_back(8, 7);
    m_enemyPathingPoints.emplace_back(7, 7);
    m_enemyPathingPoints.emplace_back(7, 2);
    m_enemyPathingPoints.emplace_back(9, 2);
    m_enemyPathingPoints.emplace_back(9, 0);
    m_enemyPathingPoints.emplace_back(4, 0);

    unsigned int quadNumber{0};
    for (unsigned int row = 0; row < m_tiles.size(); ++row) {
        for (unsigned int col = 0; col < m_tiles[row].size(); ++col) {
            // Lets assume the tiles should always be re-initialized, even if they already were.
            auto tile = m_tiles[col][row] = std::make_shared<Tile>(static_cast<TileType>(level[row][col]), col, row);

            sf::Vertex *quad = &m_vertices[quadNumber * 4];

            quad[0].position = {static_cast<float>(col * TILE_SIZE), static_cast<float>(row * TILE_SIZE)};
            quad[1].position = {static_cast<float>((col + 1) * TILE_SIZE), static_cast<float>(row * TILE_SIZE)};
            quad[2].position = {static_cast<float>((col + 1) * TILE_SIZE), static_cast<float>((row + 1) * TILE_SIZE)};
            quad[3].position = {static_cast<float>(col * TILE_SIZE), static_cast<float>((row + 1) * TILE_SIZE)};

            sf::Rect<float> texCoords = m_tileTexCoords[tile->getType()];

            quad[0].texCoords = {texCoords.left, texCoords.top};
            quad[1].texCoords = {texCoords.left + texCoords.width, texCoords.top};
            quad[2].texCoords = {texCoords.left + texCoords.width, texCoords.top + texCoords.height};
            quad[3].texCoords = {texCoords.left, texCoords.top + texCoords.height};

            quadNumber++;
        }
    }
}

Tile::Ptr Grid::getTileFromMouse(sf::Vector2i vector) const {
    return getTileFromPosition({static_cast<float>(vector.x), static_cast<float>(vector.y)});
}

Tile::Ptr Grid::getTileFromPosition(sf::Vector2f vector) const {

    sf::Vector2f position = getPosition();

    const float xRelative = vector.x - position.x;
    const float yRelative = vector.y - position.y;

    // minus 1 here. Because if the max size is lets say 650
    // 650 will be resolved to column 10, and that does not exist.
    constexpr unsigned int xMax = LEVEL_WIDTH * TILE_SIZE - 1;
    constexpr unsigned int yMax = LEVEL_HEIGHT * TILE_SIZE - 1;

    if (xRelative < 0 || yRelative < 0) return nullptr;
    if (xRelative > xMax || yRelative > yMax) return nullptr;

    auto col = static_cast<unsigned int>(std::floor(xRelative / TILE_SIZE));
    auto row = static_cast<unsigned int>(std::floor(yRelative / TILE_SIZE));

    return m_tiles[col][row];
}

sf::Vector2f Grid::getTileWindowPosition(const Tile::Ptr &tile) const {
    // This function is used, to calculate to find the position
    // on where to position the enemy and/or towers.
    sf::Vector2f gridPosition = getPosition();

    const auto yRelative = static_cast<float>(tile->getY() * TILE_SIZE);
    const auto xRelative = static_cast<float>(tile->getX() * TILE_SIZE);

    return sf::Vector2f{gridPosition.x + xRelative, gridPosition.y + yRelative};
}

sf::Vector2i Grid::getEnemySpawnTileCoordinate() const {
    if (m_enemyPathingPoints.empty()) {
        throw std::logic_error("No enemy spawn point set");
    }

    return *m_enemyPathingPoints.begin();
}

sf::Vector2i Grid::getEnemyTargetTileCoordinate() const {
    if (m_enemyPathingPoints.empty()) {
        throw std::logic_error("No enemy target point set");
    }

    return *m_enemyPathingPoints.end();
}

sf::Vector2i Grid::getEnemyPathTileCoordinate(unsigned int pathIndex) const {
    return m_enemyPathingPoints[pathIndex];
}

Tile::Ptr Grid::getTileFromCoordinate(sf::Vector2i vector) const {

    if (vector.x >= m_tiles.size() || vector.y >= m_tiles[vector.x].size()) {
        return nullptr;
    }

    return m_tiles[vector.x][vector.y];
}

Direction Grid::determineDirection(sf::Vector2<float> currentPosition, sf::Vector2<float> targetPosition) const {
    float leftOverX = targetPosition.x - currentPosition.x;
    float leftOverY = targetPosition.y - currentPosition.y;

    // Now, since we can't go diagonally. We assume that either the current and target x or y axis remain the same.

    if (leftOverX > 0.f) {
        return Direction::East;
    }

    if (leftOverX < 0.f) {
        return Direction::West;
    }

    if (leftOverY < 0.f) {
        return Direction::North;
    }

    // let the default be.. south.
    return Direction::South;
}

sf::Vector2<float> Grid::getTileWindowPositionFromTileCoordinate(sf::Vector2<int> coordinate) const {
    const Tile::Ptr tile = getTileFromCoordinate(coordinate);

    if (tile == nullptr) {
        return sf::Vector2<float>{0, 0};
    }

    return getTileWindowPosition(tile);
}
