#ifndef SFMLTEST_GAME_HPP
#define SFMLTEST_GAME_HPP

#include <SFML/Config.hpp>

class Game {
public:
    Game();

    void addGold(sf::Uint32 amount);
    void substractGold(sf::Uint32 amount);
    void setGold(sf::Uint32 amount);
    sf::Uint32 getGold();

    void addHealth(sf::Uint32 health);
    void substractHealth(sf::Uint32 health);
    void setHealth(sf::Uint32 health);
    sf::Uint32 getHealth();

private:
    sf::Uint32 m_health;
    sf::Uint32 m_gold;
};


#endif //SFMLTEST_GAME_HPP
