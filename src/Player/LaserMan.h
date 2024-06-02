#ifndef INVADERS_LASERMAN_H
#define INVADERS_LASERMAN_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class LaserMan : public Player{
    short bulletTime;
    public:
    LaserMan(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d, short bTime);
    std::unique_ptr<Bullet> shoot() override;
    virtual void specialAbility() override;
};

#endif //INVADERS_LASERMAN_H
