#ifndef INVADERS_ROCK_H
#define INVADERS_ROCK_H

#include <SFML/Graphics.hpp>

class Rock {
    int dmg;
    short speed;
    float direction;
    sf::RectangleShape rect;
    public:
    Rock(sf::Vector2f size, sf::Vector2f pos, int d, short s, float dir);
    void move();
    sf::RectangleShape getRect();
    int getDmg();
};

#endif //INVADERS_ROCK_H
