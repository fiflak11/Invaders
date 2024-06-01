#include "LaserMan.h"
#include <memory>

LaserMan::LaserMan(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, short pms, short acc, int h, int d) : Player(size,pos,bSize,pms,acc,h,d){}

std::unique_ptr<Bullet> LaserMan::shoot() {
    return std::unique_ptr<Bullet>(nullptr);
}

void LaserMan::specialAbility() {

}