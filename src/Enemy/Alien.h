#ifndef INVADERS_ALIEN_H
#define INVADERS_ALIEN_H

#include "Enemy.h"

class Alien : public Enemy{
    short bulletTime, currentShootTime=0;
    const short shootTime;
    public:
    Alien(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d, short bt, short st);
    void move() override;
    std::unique_ptr<Bullet> shoot() override;
};

#endif //INVADERS_ALIEN_H
