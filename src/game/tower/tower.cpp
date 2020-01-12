#include "tower.hpp"

void Tower::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

sf::Uint8 Tower::getRange() {
    return m_range;
}

sf::Uint32 Tower::getDamage() {
    return m_damage;
}
