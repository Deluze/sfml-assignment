#ifndef SFMLTEST_ENEMYTYPE_HPP
#define SFMLTEST_ENEMYTYPE_HPP

#include <SFML/System.hpp>

enum EnemyType : sf::Uint8
{
    Base = 0x00, // not used
    Ground = 0x01,
    Air = 0x02,
};

#endif //SFMLTEST_ENEMYTYPE_HPP
