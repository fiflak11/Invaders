#ifndef INVADERS_SOLDIER_H
#define INVADERS_SOLDIER_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class Soldier : public Player{
    short bulletSpeed;
    public:
    Soldier(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d, short bs);
    std::unique_ptr<Bullet> shoot() override;
    virtual void specialAbility() override;
};

#endif //INVADERS_SOLDIER_H
