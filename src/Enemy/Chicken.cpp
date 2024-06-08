#include "Chicken.h"
#include "../Bullet/NormalBullet.h"
#include <iostream>

Chicken::Chicken(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d, short bs, sf::Vector2f a) : Enemy(size,pos,bSize,h,d,a), bulletSpeed(bs){
    srand(time(NULL));
    currentDestination.x=rand()%(int)area.x;
    currentDestination.x=rand()%(int)area.y;
}

void Chicken::move() {
    short speed = 10;
    if(abs(rect.getPosition().x-currentDestination.x)<2*speed && abs(rect.getPosition().y-currentDestination.y)<2*speed){
        currentDestination.x=rand()%(int)area.x;
        currentDestination.y=rand()%(int)area.y;
    }
   if(rect.getPosition().x-currentDestination.x>0 && (abs(rect.getPosition().x-currentDestination.x)>=2*speed))
        rect.move(-speed,0);
   else if((abs(rect.getPosition().x-currentDestination.x)>=2*speed))
       rect.move(speed,0);
   if(rect.getPosition().y-currentDestination.y>0 && (abs(rect.getPosition().x-currentDestination.x)<=2*speed))
        rect.move(0,-speed);
   else if((abs(rect.getPosition().x-currentDestination.x)<=2*speed))
        rect.move(0,speed);
}

std::unique_ptr<Bullet> Chicken::shoot(){
    return std::make_unique<NormalBullet>(bulletSize, rect.getPosition(), dmg, bulletSpeed, 3.14/2); //down
}