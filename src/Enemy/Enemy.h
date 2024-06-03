#ifndef INVADERS_ENEMY_H
#define INVADERS_ENEMY_H

#include "SFML/Graphics.hpp"
#include "../Bullet/Bullet.h"
#include <memory>

class Enemy {
    protected:
    sf::RectangleShape rect;
    int hp, dmg;
    sf::Vector2f bulletSize;
    public:
    Enemy(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d);
    virtual ~Enemy(){};
    virtual void move(){};
    void getShot(int d);
    int getHp();
    sf::RectangleShape getRect();
    virtual std::unique_ptr<Bullet> shoot(){return std::unique_ptr<Bullet>(nullptr);}
};
#endif //INVADERS_ENEMY_H
