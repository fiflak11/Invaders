#include "Soldier.h"
#include <memory>

Soldier::Soldier(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d) : Player(size,pos,pms,acc,h,d){}

std::unique_ptr<Bullet> Soldier::shoot() {
    return std::unique_ptr<Bullet>(nullptr);
}

void Soldier::specialAbility() {

}