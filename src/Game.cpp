#include "Game.h"
#include <iostream>
#include "Player/Player.h"
#include "Player/Soldier.h"
#include "Player/LaserMan.h"
#include "Player/Snake.h"
#include "Bullet/Bullet.h"
#include <memory>

void Game::start() {
    while (window.isOpen())
    {
        events();
        playerMoveAndShoot();
        for(auto ptr = playerBullets.begin(); ptr !=playerBullets.end(); ptr++)
            ptr->get()->move();
        draw();
    }
}

Game::Game() {
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
    player = std::make_unique<Soldier>(settings.shipSize,settings.shipPosition,20,2,2,2,2);
}

void Game::playerMoveAndShoot() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move('r',settings.displayResolution[0].first);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->move('l',settings.displayResolution[0].first);
    else
        player->move('n',settings.displayResolution[0].first);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
       playerBullets.push_back(player->shoot(settings.normalBulletSize));
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
    for(auto ptr = playerBullets.begin(); ptr !=playerBullets.end(); ptr++)
        window.draw(ptr->get()->getRect());
    window.draw(player->getRect());
    window.display();
}