#include "Snake.h"
#include "../Bullet/CurlyBullet.h"
#include <memory>

Snake::Snake(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d, short bs, short bw) : Player(size,pos,bSize,pms,acc,h,d), bulletSpeed(bs),bulletWidth(bw){}

std::unique_ptr<Bullet> Snake::shoot() {
    return std::make_unique<CurlyBullet>(bulletSize,rect.getPosition(),dmg,bulletSpeed,bulletWidth);
}

void Snake::specialAbility() {

}