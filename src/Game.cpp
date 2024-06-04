#include "Game.h"
#include <iostream>
#include "Player/Player.h"
#include "Player/Soldier.h"
#include "Player/LaserMan.h"
#include "Player/Snake.h"
#include "Bullet/Bullet.h"
#include "Enemy/Enemy.h"
#include "Enemy/Chicken.h"
#include "Enemy/Alien.h"
#include <memory>

void Game::start() {
    while (window.isOpen())
    {
        events();
        playerMoveAndShoot();
        bulletsMove();
        draw();
    }
}

Game::Game() {
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
    //player = std::make_unique<Soldier>(settings.shipSize,settings.shipPosition,settings.normalBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed);
    player = std::make_unique<Snake>(settings.shipSize,settings.shipPosition,settings.curlyBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed,settings.playerCurlyBulletWidth);
    //player = std::make_unique<LaserMan>(settings.shipSize,settings.shipPosition,settings.laserSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.laserPlayerTime);
}

void Game::playerMoveAndShoot() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move('r',settings.displayResolution[0].first);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->move('l',settings.displayResolution[0].first);
    else
        player->move('n',settings.displayResolution[0].first);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
       playerBullets.push_back(player->shoot());
    }
}

void Game::events() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::draw(){
    window.clear();
    for(auto ptr = chickens.begin(); ptr !=chickens.end(); ptr++)
        window.draw(ptr->get()->getRect());
    for(auto ptr = playerBullets.begin(); ptr !=playerBullets.end(); ptr++)
        window.draw(ptr->get()->getRect());
    for(auto ptr = chickenBullets.begin(); ptr !=chickenBullets.end(); ptr++)
        window.draw(ptr->get()->getRect());
    window.draw(player->getRect());
    window.display();
}

void Game::bulletsMove() {
    for(auto ptr = playerBullets.begin(); ptr !=playerBullets.end(); ptr++)
        ptr->get()->move();
}