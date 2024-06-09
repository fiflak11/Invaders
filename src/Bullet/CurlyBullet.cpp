#include "CurlyBullet.h"
#include <iostream>

CurlyBullet::CurlyBullet(sf::Vector2f size, sf::Vector2f pos, int DMG, short s, short w) : Bullet(size, DMG), speed(s), width(w){
    rect.setPosition(pos);
    rect.setFillColor(sf::Color::Blue);
}

void CurlyBullet::move() {
    if(direction)
        offset--;
    else
        offset++;
    if(offset>width || offset<-width)
        direction=!direction;
    rect.move(offset,-speed);
    aliveTime--;
    if(aliveTime<0)
        alive=false;
}