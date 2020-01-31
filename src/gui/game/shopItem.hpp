#ifndef SFMLTEST_SHOPITEM_HPP
#define SFMLTEST_SHOPITEM_HPP

#include "../UIElement.hpp"
#include "../../game/tower/tower.hpp"

#include <memory>
#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class ShopItem : public UIElement, public sf::Drawable {
public:
    ShopItem(TowerType towerType, sf::Text towerText, sf::Text goldText);
    ShopItem();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    std::shared_ptr<Tower> getTower();

private:
    sf::Text m_towerName;

    sf::Text m_goldText;

    TowerType m_towerType;

    sf::RectangleShape m_background;
};


#endif //SFMLTEST_SHOPITEM_HPP
