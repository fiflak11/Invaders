#include "LaserMan.h"
#include <memory>

LaserMan::LaserMan(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d) : Player(size,pos,pms,acc,h,d){}

std::unique_ptr<Bullet> LaserMan::shoot(sf::Vector2f size) {
    return std::unique_ptr<Bullet>(nullptr);
}

void LaserMan::specialAbility() {

}