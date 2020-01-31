#include "tower.hpp"
#include "../grid.hpp"

#include <utility>


Tower::Tower(TowerType towerType) : m_type(towerType), m_range(2), m_damage(0), m_fireRate(0), m_selected(false) {
    m_radiusShape.setFillColor(sf::Color{235, 79, 52, 128});
//    m_radiusShape.setPosition(10, 10);
//    m_radiusShape.setPointCount(5);

}

void Tower::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    if (m_selected) {
        target.draw(m_radiusShape, states);
    }

    target.draw(m_sprite, states);
}

unsigned int Tower::getRange() {
    return m_range;
}

unsigned int Tower::getFireRate() {
    return m_fireRate;
}

unsigned int Tower::getDamage() {
    return m_damage;
}

void Tower::setTexture(const sf::Texture &texture, sf::Rect<int> textureCoords) {
    m_sprite.setTexture(texture);
    m_sprite.setTextureRect(textureCoords);
}

TowerType Tower::getTowerType() {
    return m_type;
}

void Tower::lockOn(std::weak_ptr<Enemy> enemy) {
    m_focussedEnemy = std::move(enemy);
}

void Tower::setSelected(bool selected) {
    m_selected = selected;

    m_radiusShape.setPosition(TILE_SIZE / 2.f, TILE_SIZE / 2.f + 75 - TILE_SIZE);
    m_radiusShape.setRadius(static_cast<float>(m_range * TILE_SIZE));
    m_radiusShape.setOrigin(m_radiusShape.getRadius(), m_radiusShape.getRadius());
}
