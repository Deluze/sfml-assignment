#ifndef SFMLTEST_TOWERCOMPONENT_HPP
#define SFMLTEST_TOWERCOMPONENT_HPP

#include <memory>

class Tower;

class Enemy;

class TowerComponent {
public:
    virtual void onTowerShoot(const std::shared_ptr<Tower> &tower);

    virtual void onTowerBulletHit(const std::shared_ptr<Tower> &tower, const std::shared_ptr<Enemy> &enemy);
};


#endif //SFMLTEST_TOWERCOMPONENT_HPP
