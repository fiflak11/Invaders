#include "Laser.h"

Laser::Laser(sf::Vector2f size, sf::Vector2f pos, int DMG, short t) : Bullet(size,DMG), time(t){
    rect.setPosition(pos);
}

void Laser::move() {
    time--;
    if(time<0)
        alive=false;
}