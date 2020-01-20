#include "tower.hpp"


Tower::Tower(TowerType towerType) : m_type(towerType), m_range(0), m_damage(0) {

}

void Tower::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

sf::Uint8 Tower::getRange() {
    return m_range;
}

sf::Uint32 Tower::getDamage() {
    return m_damage;
}

void Tower::setSprite(const sf::Sprite& sprite) {
    m_sprite = sprite;
}

