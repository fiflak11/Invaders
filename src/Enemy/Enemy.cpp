#include "Enemy.h"

Enemy::Enemy(sf::Vector2f size, sf::Vector2f pos, sf::Vector2f bSize, int h, int d) : bulletSize(bSize), hp(h), dmg(d){
    rect.setPosition(pos);
    rect.setSize(size);
    rect.setOrigin(size.x/2, size.y/2);
}

void Enemy::getShot(int d) {
    hp-=d;
}

sf::RectangleShape Enemy::getRect() {
    return rect;
}

int Enemy::getHp() {
    return hp;
}