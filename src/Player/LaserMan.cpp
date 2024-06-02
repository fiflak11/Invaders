#include "LaserMan.h"
#include "../Bullet/Laser.h"
#include <memory>

LaserMan::LaserMan(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d, short bTime) : Player(size,pos,bSize,pms,acc,h,d), bulletTime(bTime){}

std::unique_ptr<Bullet> LaserMan::shoot() {
    return std::make_unique<Laser>(bulletSize,rect.getPosition(),dmg,bulletTime);
}

void LaserMan::specialAbility() {

}