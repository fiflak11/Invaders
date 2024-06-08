#ifndef INVADERS_CHICKEN_H
#define INVADERS_CHICKEN_H

#include "Enemy.h"

class Chicken : public Enemy{
    short bulletSpeed;
    sf::Vector2f currentDestination;
    public:
    Chicken(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d, short bs, sf::Vector2f a);
    void move() override;
    std::unique_ptr<Bullet> shoot() override;
};


#endif //INVADERS_CHICKEN_H
