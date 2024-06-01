#ifndef INVADERS_PLAYER_H
#define INVADERS_PLAYER_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "../Bullet/Bullet.h"

class Player {
    protected:
    sf::RectangleShape rect;
    short playerSpeed=0, playerMaxSpeed, acceleration, lvl=0;
    int hp, dmg;
    public:
    Player(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d);
    virtual ~Player(){};
    void move(char,int);
    void getShot(int damage);
    sf::RectangleShape getRect();
    int getHp();
    virtual std::unique_ptr<Bullet> shoot(sf::Vector2f size){return std::unique_ptr<Bullet>(nullptr);}
    virtual void specialAbility(){};
};

#endif //INVADERS_PLAYER_H
