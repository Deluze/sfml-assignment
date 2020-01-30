#include "enemy.hpp"

#include <iostream>

Enemy::Enemy(unsigned int health, EnemyType type, bool isBoss)
	: GameObject(), m_type(type), m_health(health), m_isBoss(isBoss), m_progress(0), m_pathingIndex(0), m_moveX(0.f), m_moveY(0.f) {
	m_initialHealth = health;

	m_foreGroundHealthbar.setFillColor(sf::Color::Green);
	m_backGroundHealthbar.setFillColor(sf::Color::Red);

	m_foreGroundHealthbar.setSize({ HEALTH_BAR_LENGTH, HEALTH_BAR_HEIGHT });
	m_backGroundHealthbar.setSize({ HEALTH_BAR_LENGTH, HEALTH_BAR_HEIGHT });
}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_sprite, states);

	if (m_initialHealth > m_health) {
		target.draw(m_backGroundHealthbar, states);
		target.draw(m_foreGroundHealthbar, states);
	}
}

void Enemy::takeDamage(unsigned int damage) {
	if (damage > m_health) {
		m_health = 0;
		return;
	}
	m_health -= damage;

	const float healthPercentage = 100.f / static_cast<float>(m_initialHealth) * static_cast<float>(m_health);
	m_foreGroundHealthbar.setSize(
		{ HEALTH_BAR_LENGTH / 100.f * healthPercentage, HEALTH_BAR_HEIGHT });
}

unsigned int Enemy::getHealth() {
	return m_health;
}

bool Enemy::isAir() {
	return m_type == EnemyType::AirEnemy;
}

bool Enemy::isGrounded() {
	return m_type == EnemyType::GroundEnemy;
}

bool Enemy::isBoss() {
	return m_isBoss;
}

unsigned int Enemy::getProgress() {
	return m_progress;
}

void Enemy::setTexture(const sf::Texture &texture, const sf::Rect<int> &texCoords) {
	m_sprite.setTexture(texture);
	m_sprite.setTextureRect(texCoords);

	// Set the origin to the center of the sprite
	// Since that's more convenient for us.
	m_sprite.setOrigin(texCoords.width / 2.f, texCoords.height / 2.f);
}

EnemyType Enemy::getType() {
	return m_type;
}

void Enemy::step() {
	move(m_moveX, m_moveY);

	if (m_health >= m_initialHealth) {
		// No need to position our healthbar continously, if it's not visible.
		return;
	}

	const sf::Vector2f position = getPosition();
	m_backGroundHealthbar.setPosition(position.x - 100, position.y + 20.f);
	m_foreGroundHealthbar.setPosition(position.x - 100, position.y + 20.f);
}

unsigned int Enemy::getPathingIndex() {
	return m_pathingIndex;
}
