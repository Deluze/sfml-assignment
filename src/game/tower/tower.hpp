#ifndef SFMLTEST_TOWER_HPP
#define SFMLTEST_TOWER_HPP

#include "../gameObject.hpp"
#include "towerType.hpp"

#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tower : public GameObject {
public:
    explicit Tower(TowerType towerType);

    using Ptr = std::shared_ptr<Tower>;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Uint8 getRange();
    sf::Uint32 getDamage();
    TowerType getTowerType();

    void setTexture(const sf::Texture& texture, sf::Rect<int> textureCoords);
private:
    sf::Uint8 m_range;
    sf::Uint32 m_damage;
    sf::Sprite m_sprite;

    TowerType m_type;
};


#endif //SFMLTEST_TOWER_HPP
