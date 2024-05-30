#ifndef INVADERS_NORMALBULLET_H
#define INVADERS_NORMALBULLET_H

#include "Bullet.h"

class NormalBullet : public Bullet{
    short speed;
    float direction;
    public:
    NormalBullet();
    void move() override;
};

#endif //INVADERS_NORMALBULLET_H
