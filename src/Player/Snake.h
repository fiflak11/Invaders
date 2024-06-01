#ifndef INVADERS_SNAKE_H
#define INVADERS_SNAKE_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class Snake : public Player{
    short bulletSpeed,bulletWidth;
    public:
    Snake(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d, short bs, short bw);
    std::unique_ptr<Bullet> shoot() override;
    virtual void specialAbility() override;
};
#endif //INVADERS_SNAKE_H
