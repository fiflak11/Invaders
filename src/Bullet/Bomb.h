#ifndef INVADERS_BOMB_H
#define INVADERS_BOMB_H

#include "Bullet.h"

class BombBullet : public Bullet{
    short speed;
    public:
    BombBullet();
    void move() override;
};

#endif //INVADERS_BOMB_H
