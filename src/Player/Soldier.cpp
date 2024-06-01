#include "Soldier.h"
#include "../Bullet/NormalBullet.h"
#include <memory>

Soldier::Soldier(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d, short bs) : Player(size,pos,bSize,pms,acc,h,d), bulletSpeed(bs){}

std::unique_ptr<Bullet> Soldier::shoot() {
    return std::make_unique<NormalBullet>(bulletSize,rect.getPosition(),dmg,bulletSpeed,-3.14/2); // UP
}

void Soldier::specialAbility() {

}