#ifndef SFMLTEST_TOWERTYPE_HPP
#define SFMLTEST_TOWERTYPE_HPP

#include <SFML/System.hpp>

enum TowerType : sf::Uint8
{
    Base = 0x00, // unused
    Gun = 0x01,
    Bow = 0x02,
    Ice = 0x03,
    Poison = 0x04,
    Fire = 0x05,
    Bomb = 0x06,
    Dark = 0x07,
    Electricity = 0x08,
    Count,
};

#endif //SFMLTEST_TOWERTYPE_HPP
