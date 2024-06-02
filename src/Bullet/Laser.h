#ifndef INVADERS_LASER_H
#define INVADERS_LASER_H

#include "Bullet.h"

class Laser : public Bullet{
    int time;
    public:
    Laser(sf::Vector2f size, sf::Vector2f pos, int DMG, short t);
    void move() override;
};
#endif //INVADERS_LASER_H
