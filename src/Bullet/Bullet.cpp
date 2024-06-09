#include "Bullet.h"

#include "SFML/Graphics.hpp"

Bullet::Bullet(sf::Vector2f size, int DMG) : dmg(DMG){
    rect.setSize(size);
    rect.setOrigin(size.x/2, size.y/2);
    rect.setFillColor(sf::Color::Blue);
}

int Bullet::getDmg() {
    return dmg;
}

sf::RectangleShape Bullet::getRect() {
    return rect;
}

bool Bullet::isAlive() {
    return alive;
}