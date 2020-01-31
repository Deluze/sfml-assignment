#include "enemyManager.hpp"

void EnemyManager::initialize() {
    m_enemyTextureAtlas.loadFromFile("asset/texture/enemies.png");

    m_enemyTexCoords[EnemyType::GroundEnemy] = {0, 0, 35, 35};
    m_enemyTexCoords[EnemyType::AirEnemy] = {35, 0, 35, 35};
}

void EnemyManager::removeEnemy(const Enemy::Ptr &enemy) {
    m_enemies.erase(std::remove(m_enemies.begin(), m_enemies.end(), enemy));
}

void EnemyManager::addEnemy(const Enemy::Ptr &enemy) {
    enemy->setTexture(m_enemyTextureAtlas, m_enemyTexCoords[enemy->getType()]);
    m_enemies.push_back(enemy);
}

Enemy::Ptr EnemyManager::getMostProgressedEnemy() {
    return *std::max_element(m_enemies.begin(), m_enemies.end(), [](const Enemy::Ptr &lhs, const Enemy::Ptr &rhs) {
        return lhs->getProgress() < rhs->getProgress();
    });
}

void EnemyManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &enemy : m_enemies) {
        target.draw(*enemy, states);
    }
}

void EnemyManager::tick() {
    for (const auto &enemy : m_enemies) {
        enemy->step();
    }
}

std::size_t EnemyManager::getEnemyCount() {
    return m_enemies.size();
}

void EnemyManager::handleEnemyPathing(const Grid &grid) {
    for (const auto &enemy : m_enemies) {
        if (!enemy->needsNewPath()) {
            continue;
        }

        const sf::Vector2<int> targetTileCoordinate = grid.getEnemyPathTileCoordinate(enemy->getPathingIndex() + 1);
        const sf::Vector2<float> targetPosition = grid.getTileWindowPositionFromTileCoordinate(targetTileCoordinate);

        // to align stuff, we need to add 25 to x and y of the tile target position (since it's origin is in the left top)
        const Direction direction = grid.determineDirection(enemy->getPosition(), {targetPosition.x + 25.f, targetPosition.y + 25.f});

        enemy->setDirection(direction, {targetPosition.x + 25.f, targetPosition.y + 25.f});
    }
}


