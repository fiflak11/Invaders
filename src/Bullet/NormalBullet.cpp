#include "NormalBullet.h"
#include <cmath>

NormalBullet::NormalBullet(sf::Vector2f size, sf::Vector2f pos, int DMG, short s, float dir) : Bullet(size, DMG), speed(s), direction(dir){
    rect.setPosition(pos);
}

void NormalBullet::move() {
    rect.move(speed*cos(direction),speed*sin(direction));
}