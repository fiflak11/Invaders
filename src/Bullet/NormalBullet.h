#ifndef INVADERS_NORMALBULLET_H
#define INVADERS_NORMALBULLET_H

#include "Bullet.h"

class NormalBullet : public Bullet{
    short speed, aliveTime=300;
    float direction;
    public:
    NormalBullet(sf::Vector2f size, sf::Vector2f pos, int DMG, short s, float dir);
    void move() override;
};

#endif //INVADERS_NORMALBULLET_H
