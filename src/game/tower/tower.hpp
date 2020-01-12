#ifndef SFMLTEST_TOWER_HPP
#define SFMLTEST_TOWER_HPP

#include "../gameObject.hpp"

class Tower : public GameObject {
public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFMLTEST_TOWER_HPP
