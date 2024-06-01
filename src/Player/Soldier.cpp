#include "Soldier.h"
#include "../Bullet/NormalBullet.h"
#include <memory>

Soldier::Soldier(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d, short bs) : Player(size,pos,pms,acc,h,d), bulletSpeed(bs){}

std::unique_ptr<Bullet> Soldier::shoot(sf::Vector2f size) {
    return std::make_unique<NormalBullet>(size,rect.getPosition(),dmg,bulletSpeed,-3.14/2); // UP
}

void Soldier::specialAbility() {

}