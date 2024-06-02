#ifndef INVADERS_BULLET_H
#define INVADERS_BULLET_H

#include "SFML/Graphics.hpp"

class Bullet {
    protected:
    bool alive=true;
    int dmg;
    sf::RectangleShape rect;
    public:
    Bullet(sf::Vector2f size, int DMG);
    virtual ~Bullet(){};
    virtual void move(){};
    sf::RectangleShape getRect();
    int getDmg();
    bool isAlive();
};

#endif //INVADERS_BULLET_H
