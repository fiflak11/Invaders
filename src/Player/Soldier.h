#ifndef INVADERS_SOLDIER_H
#define INVADERS_SOLDIER_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class Soldier : public Player{
    public:
    Soldier(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d);
    std::unique_ptr<Bullet> shoot() override;
    virtual void specialAbility() override;
};

#endif //INVADERS_SOLDIER_H
