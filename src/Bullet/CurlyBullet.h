#ifndef INVADERS_CURLYBULLET_H
#define INVADERS_CURLYBULLET_H

#include "Bullet.h"

class CurlyBullet : public Bullet{
    short speed, width;
    public:
    CurlyBullet();
    void move() override;
};

#endif //INVADERS_CURLYBULLET_H
