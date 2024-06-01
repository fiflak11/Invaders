#ifndef INVADERS_LASERMAN_H
#define INVADERS_LASERMAN_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class LaserMan : public Player{
    public:
    LaserMan(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d);
    std::unique_ptr<Bullet> shoot() override;
    virtual void specialAbility() override;
};

#endif //INVADERS_LASERMAN_H