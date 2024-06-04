#include "Alien.h"
#include "../Bullet/Laser.h"

Alien::Alien(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d, short bt, short st) : Enemy(size,pos,bSize,h,d), bulletTime(bt), shootTime(st){}

void Alien::move() {
    if(!currentShootTime)
        rect.move(1,0);
    else
        currentShootTime--;
}

std::unique_ptr<Bullet> Alien::shoot(){
    currentShootTime=shootTime;
    return std::make_unique<Laser>(bulletSize, rect.getPosition(), dmg, bulletTime); //down
}