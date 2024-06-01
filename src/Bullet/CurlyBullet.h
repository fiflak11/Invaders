#ifndef INVADERS_CURLYBULLET_H
#define INVADERS_CURLYBULLET_H

#include "Bullet.h"

class CurlyBullet : public Bullet{
    short speed, width, offset=0;
    bool direction=false;
    public:
    CurlyBullet(sf::Vector2f size, sf::Vector2f pos, int DMG, short s, short w);
    void move() override;
};

#endif //INVADERS_CURLYBULLET_H
