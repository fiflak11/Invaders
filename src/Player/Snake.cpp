#include "Snake.h"
#include <memory>

Snake::Snake(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d) : Player(size,pos,pms,acc,h,d){}

std::unique_ptr<Bullet> Snake::shoot() {
    return std::unique_ptr<Bullet>(nullptr);
}

void Snake::specialAbility() {

}