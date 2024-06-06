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
        addEnemy();
        events();
        moveEverything();
        draw();
    }
}

Game::Game() {
    srand(time(NULL));
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
    //player = std::make_unique<Soldier>(settings.shipSize,settings.shipPosition,settings.normalBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed);
    player = std::make_unique<Snake>(settings.shipSize,settings.shipPosition,settings.curlyBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed,settings.playerCurlyBulletWidth);
    //player = std::make_unique<LaserMan>(settings.shipSize,settings.shipPosition,settings.laserSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.laserPlayerTime);
}

void Game::moveEverything() {
    playerMoveAndShoot();
    moveList<Bullet>(playerBullets);
    moveList<Bullet>(chickenBullets);
    moveList<Rock>(rocks);
    moveList<Enemy>(chickens);
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
    drawList<Bullet>(chickenBullets);
    drawList<Bullet>(playerBullets);
    drawList<Rock>(rocks);
    drawList<Enemy>(chickens);
    window.draw(player->getRect());
    window.display();
}

template<typename object>
void Game::drawList(std::list<std::unique_ptr<object>>& l) {
    for(auto ptr = l.begin(); ptr !=l.end(); ptr++)
        window.draw(ptr->get()->getRect());
}

template<typename object>
void Game::moveList(std::list<std::unique_ptr<object>>& l) {
    for(auto ptr = l.begin(); ptr !=l.end(); ptr++)
        ptr->get()->move();
}

void Game::addEnemy() {
    short r = rand()%4;
    sf::Vector2f pos{rand()%1000+100,-100};
    switch (r) {
        case 0: // rock
            rocks.push_front(std::make_unique<Rock>(settings.rockSize,pos,settings.rockDmg,settings.rockSpeed,3.14/2));
            break;
        case 1: // normal chicken
            chickens.push_front(std::make_unique<Chicken>(settings.chickenSize,pos,settings.normalBulletSize,settings.chickenHp,settings.chickenDmg,settings.chickenBulletSpeed));
            break;
        case 2: // big chicken
            chickens.push_front(std::make_unique<Chicken>(settings.bigChickenSize,pos,settings.normalBulletSize,settings.bigChickenHp,settings.bigChickenDmg,settings.bigChickenBulletSpeed));
            break;
        case 3: // alien
            chickens.push_front(std::make_unique<Alien>(settings.alienSize,pos,settings.laserSize,settings.alienHp,settings.alienDmg,settings.alienBulletTime,settings.alienShootTime));
            break;
    }
}