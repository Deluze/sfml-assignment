#include "enemy.hpp"

Enemy::Enemy(unsigned int health, EnemyType type, bool isBoss) : GameObject(), m_type(type), m_health(health), m_isBoss(isBoss) {
    m_foreGroundHealthbar.setFillColor(sf::Color::Green);
    m_backGroundHealthbar.setFillColor(sf::Color::Red);

    m_foreGroundHealthbar.setSize({HEALTH_BAR_LENGTH, HEALTH_BAR_HEIGHT});
    m_backGroundHealthbar.setSize({HEALTH_BAR_LENGTH, HEALTH_BAR_HEIGHT});
}

void Enemy::takeDamage(unsigned int damage) {
    if(damage > m_health) {
        m_health = 0;
        return;
    }

    m_health -= damage;
}

unsigned int Enemy::getHealth() {
    return m_health;
}

bool Enemy::isAir() {
    return m_type == EnemyType::Air;
}

bool Enemy::isGrounded() {
    return m_type == EnemyType::Ground;
}

bool Enemy::isBoss() {
    return m_isBoss;
}
