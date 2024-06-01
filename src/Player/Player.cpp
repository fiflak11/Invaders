#include "Player.h"
#include "SFML/Graphics.hpp"

Player::Player(sf::Vector2f size, sf::Vector2f pos, short pms, short acc, int h, int d) : playerMaxSpeed(pms), acceleration(acc), hp(h), dmg(d){
    rect.setSize(size);
    rect.setOrigin(size.x/2, size.y/2);
    rect.setPosition(pos);
}

inline void Player::getShot(int damage) {
    hp-=damage;
}

inline int Player::getHp() {
    return hp;
}

sf::RectangleShape Player::getRect() {
    return rect;
}

void Player::move(char direction, int rigthBorder){
    if(direction=='r' && playerSpeed<playerMaxSpeed)
        playerSpeed+=acceleration;
    else if(direction=='l' && playerSpeed>-playerMaxSpeed)
        playerSpeed-=acceleration;
    else if(direction=='n')
        if(playerSpeed>0)
            playerSpeed-=acceleration/2;
        else if(playerSpeed<0)
            playerSpeed+=acceleration/2;
    sf::Vector2f pos = rect.getPosition();
    if(pos.x<rect.getSize().x/2 || pos.x+rect.getSize().x/2>rigthBorder)
        playerSpeed=-playerSpeed;
    rect.setPosition(pos.x + playerSpeed, pos.y);
}