#ifndef SFMLTEST_TOWER_HPP
#define SFMLTEST_TOWER_HPP

#include "../gameObject.hpp"
#include "towerType.hpp"
#include "../enemy/enemy.hpp"
#include "component/towerComponent.hpp"

#include <memory>
#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tower : public GameObject {
public:
    explicit Tower(TowerType towerType);

    using Ptr = std::shared_ptr<Tower>;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Uint8 getRange();

    sf::Uint32 getDamage();

    sf::Uint16 getFireRate();

    TowerType getTowerType();

    void setTexture(const sf::Texture &texture, sf::Rect<int> textureCoords);

private:
    // The range of the tower
    // this will be the radius of a square
    sf::Uint8 m_range;

    // Damage the tower will be doing
    // each shot
    sf::Uint32 m_damage;

    // FireTower rate of the tower, in milliseconds.
    // 1000 means 1 bullet a second
    // 500 means 2 bullets a second.. etc
    sf::Uint16 m_fireRate;

    // Sprite of the turret.
    // Texture and texture coords will be provider by tower manager
    sf::Sprite m_sprite;

    // Type of tower
    TowerType m_type;

    std::vector<TowerComponent> m_components;

    // Currently focused enemy
    std::weak_ptr<Enemy> m_focussedEnemy;
};


#endif //SFMLTEST_TOWER_HPP
