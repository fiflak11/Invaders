#include "Chicken.h"
#include "../Bullet/NormalBullet.h"

Chicken::Chicken(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d, short bs) : Enemy(size,pos,bSize,h,d), bulletSpeed(bs){}

void Chicken::move() {
    rect.move(0,1);
}

std::unique_ptr<Bullet> Chicken::shoot(){
    return std::make_unique<NormalBullet>(bulletSize, rect.getPosition(), dmg, bulletSpeed, 3.14/2); //down
}