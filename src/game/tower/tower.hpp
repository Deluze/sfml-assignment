#ifndef SFMLTEST_TOWER_HPP
#define SFMLTEST_TOWER_HPP

#include "../gameObject.hpp"

#include <memory>

class Tower : public GameObject {
public:

    using Ptr = std::shared_ptr<Tower>;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Uint8 getRange();
    sf::Uint32 getDamage();

private:
    sf::Uint8 m_range;
    sf::Uint32 m_damage;
};


#endif //SFMLTEST_TOWER_HPP
