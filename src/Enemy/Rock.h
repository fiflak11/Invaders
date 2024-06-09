#ifndef INVADERS_ROCK_H
#define INVADERS_ROCK_H

#include <SFML/Graphics.hpp>

class Rock {
    int dmg;
    short speed, timeAlive=300;
    float direction;
    bool alive = true;
    sf::RectangleShape rect;
    public:
    Rock(sf::Vector2f size, sf::Vector2f pos, int d, short s, float dir);
    void move();
    sf::RectangleShape getRect();
    int getDmg();
    bool isAlive();
};

#endif //INVADERS_ROCK_H
