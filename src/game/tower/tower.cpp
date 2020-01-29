#include "tower.hpp"


Tower::Tower(TowerType towerType) : m_type(towerType), m_range(0), m_damage(0), m_fireRate(0) {

}

void Tower::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(m_sprite, states);
}

sf::Uint8 Tower::getRange() {
    return m_range;
}

sf::Uint16 Tower::getFireRate() {
    return m_fireRate;
}

sf::Uint32 Tower::getDamage() {
    return m_damage;
}

void Tower::setTexture(const sf::Texture &texture, sf::Rect<int> textureCoords) {
    m_sprite.setTexture(texture);
    m_sprite.setTextureRect(textureCoords);
}

TowerType Tower::getTowerType() {
    return m_type;
}
