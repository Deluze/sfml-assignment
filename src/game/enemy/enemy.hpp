#ifndef SFMLTEST_ENEMY_HPP
#define SFMLTEST_ENEMY_HPP

#define HEALTH_BAR_LENGTH 50
#define HEALTH_BAR_HEIGHT 5

#include "../gameObject.hpp"
#include "enemyType.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Enemy : public GameObject {
public:
    explicit Enemy(unsigned int health, EnemyType type = EnemyType::Base, bool isBoss = false);

    void takeDamage(unsigned int damage);
    unsigned int getHealth();

    bool isAir();
    bool isGrounded();
    bool isBoss();
private:
    EnemyType m_type;
    sf::Sprite m_sprite;
    sf::RectangleShape m_backGroundHealthbar;
    sf::RectangleShape m_foreGroundHealthbar;
    unsigned int m_health;
    unsigned int m_progress;
    bool m_isBoss;
};


#endif //SFMLTEST_ENEMY_HPP
