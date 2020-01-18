#include "grid.hpp"

#include <cmath>

Grid::Grid() : m_vertices(sf::VertexArray{sf::PrimitiveType::Quads, LEVEL_HEIGHT * LEVEL_WIDTH * 4})
{
    m_tileset.loadFromFile("asset/texture/tileset.png");
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset;

    target.draw(m_vertices, states);
}

void Grid::initialize() {
    unsigned int quadNumber{0};
    for (unsigned int row = 0; row < m_tiles.size(); ++row) {
        for (unsigned int col = 0; col < m_tiles[row].size(); ++col) {
            // Lets assume the tiles should always be re-initialized, even if they already were.
            auto tile = m_tiles[row][col] = std::make_shared<Tile>(TileType::Grass, col, row);

            sf::Vertex* quad = &m_vertices[quadNumber * 4];

            quad[0].position = {static_cast<float>(col * TILE_SIZE), static_cast<float>(row * TILE_SIZE)};
            quad[1].position = {static_cast<float>((col + 1) * TILE_SIZE), static_cast<float>(row * TILE_SIZE)};
            quad[2].position = {static_cast<float>((col + 1) * TILE_SIZE), static_cast<float>((row + 1) * TILE_SIZE)};
            quad[3].position = {static_cast<float>(col * TILE_SIZE), static_cast<float>((row + 1) * TILE_SIZE)};

            sf::Rect<float> texCoords = tile->getTexCoords();

            quad[0].texCoords = {texCoords.left, texCoords.top};
            quad[1].texCoords = {texCoords.left + texCoords.width, texCoords.top};
            quad[2].texCoords = {texCoords.left + texCoords.width, texCoords.top + texCoords.height};
            quad[3].texCoords = {texCoords.left, texCoords.top + texCoords.height};

            quadNumber++;
        }
    }
}

Tile::Ptr Grid::getTileFromMouse(sf::Vector2i vector) {
    return getTileFromPosition({
        static_cast<float>(vector.x),
        static_cast<float>(vector.y)
    });
}

Tile::Ptr Grid::getTileFromPosition(sf::Vector2f vector) {

    sf::Vector2f position = getPosition();

    const float xRelative = vector.x - position.x;
    const float yRelative = vector.y - position.y;

    constexpr unsigned int xMax = LEVEL_WIDTH * TILE_SIZE;
    constexpr unsigned int yMax = LEVEL_HEIGHT * TILE_SIZE;

    if(xRelative < 0 || yRelative < 0) return nullptr;
    if(xRelative > xMax || yRelative > yMax) return nullptr;

    auto col = static_cast<unsigned int>(std::floor(xRelative / TILE_SIZE));
    auto row = static_cast<unsigned int>(std::floor(yRelative / TILE_SIZE));

    return m_tiles[col][row];
}

sf::Vector2f Grid::getTileWindowPosition(const Tile::Ptr& tile) {
    sf::Vector2f gridPosition = getPosition();

    const auto xRelative = static_cast<float>(tile->getX() * TILE_SIZE);
    const auto yRelative = static_cast<float>(tile->getY() * TILE_SIZE);

    return sf::Vector2f{gridPosition.x + xRelative, gridPosition.y + yRelative};
}
