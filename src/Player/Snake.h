#ifndef INVADERS_SNAKE_H
#define INVADERS_SNAKE_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class Snake : public Player{
    public:
    Snake(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d);
    std::unique_ptr<Bullet> shoot(sf::Vector2f size) override;
    virtual void specialAbility() override;
};
#endif //INVADERS_SNAKE_H
