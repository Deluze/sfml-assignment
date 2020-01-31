#ifndef SFMLTEST_ENEMY_HPP
#define SFMLTEST_ENEMY_HPP

#define HEALTH_BAR_LENGTH 35
#define HEALTH_BAR_HEIGHT 1

#include "../gameObject.hpp"
#include "enemyType.hpp"
#include "../direction.hpp"

#include <memory>
#include <functional>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Enemy : public GameObject {
public:
    using Ptr = std::shared_ptr<Enemy>;

    explicit Enemy(unsigned int health, EnemyType type = EnemyType::GroundEnemy, bool isBoss = false);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void step();

    void setDirection(Direction direction, sf::Vector2<float> targetPosition);

    void setTexture(const sf::Texture &texture, const sf::Rect<int> &texCoords);

    bool needsNewPath();

    void takeDamage(unsigned int damage);

    bool isGrounded();

    bool isAir();

    bool isBoss();

    unsigned int getProgress();

    unsigned int getHealth();

    unsigned int getPathingIndex();

    EnemyType getType();

private:
    // Type of the enemy. This is not a race
    EnemyType m_type;

    // Sprite of the enemy. Texture being provided by parent class
    sf::Sprite m_sprite;

    sf::RectangleShape m_backGroundHealthbar;
    sf::RectangleShape m_foreGroundHealthbar;

    // Health of enemy
    unsigned int m_health;

    // As the name implies.
    // The amount of health the enemy used to have
    unsigned m_initialHealth;

    // Progress of the enemy in the map. Could be anything.
    // Higher the progress, more chance of being focused by a tower.
    unsigned int m_progress;

    // The current path this enemy is on.
    unsigned int m_pathingIndex;

    // If this enemy is a boss or not
    bool m_isBoss;

    // The amount of X this enemy has to move each tick
    float m_moveX;

    // The amount of Y this enemy has to move each tick
    float m_moveY;

    // The amount of distance the enemy needs to cover
    // until it needs to request a new path.
    float m_distance;

    // Target the enemy is currently walking towards
    sf::Vector2<float> m_target;
};


#endif //SFMLTEST_ENEMY_HPP
