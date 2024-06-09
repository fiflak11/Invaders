#include "Alien.h"
#include "../Bullet/Laser.h"

Alien::Alien(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d, short bt, short st, sf::Vector2f a, short l) : Enemy(size,pos,bSize,h,d,a), bulletTime(bt), shootTime(st), line(l){
    rect.setFillColor(sf::Color::Yellow);
}

void Alien::move() {
    if(rect.getPosition().x<20.0 || rect.getPosition().x>area.x-20)
        leftOrRight = !leftOrRight;
    if(!currentShootTime && rect.getPosition().y<line)
        rect.move(0,2);
    else if(!currentShootTime && leftOrRight)
        rect.move(2,0);
    else if(!currentShootTime)
        rect.move(-2,0);
    else
        currentShootTime--;
}

std::unique_ptr<Bullet> Alien::shoot(){
    currentShootTime=shootTime;
    return std::make_unique<Laser>(bulletSize, rect.getPosition(), dmg, bulletTime); //down
}