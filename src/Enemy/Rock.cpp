#include "Rock.h"
#include <cmath>

Rock::Rock(sf::Vector2f size, sf::Vector2f pos, int d, short s, float dir) : dmg(d), speed(s), direction(dir){
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setOrigin(size.x/2,size.y/2);
}

void Rock::move() {
    rect.move(speed*cos(direction),speed*sin(direction));
}

int Rock::getDmg() {
    return dmg;
}

sf::RectangleShape Rock::getRect() {
    return rect;
}