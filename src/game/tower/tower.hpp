#ifndef SFMLTEST_TOWER_HPP
#define SFMLTEST_TOWER_HPP

#include "../gameObject.hpp"


class Tower : public GameObject {
public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Uint8 getRange();
    sf::Uint32 getDamage();

private:
    sf::Uint8 m_range;
    sf::Uint32 m_damage;
};


#endif //SFMLTEST_TOWER_HPP
