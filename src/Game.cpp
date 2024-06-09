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
        addEnemy();
        enemyShoot();
        moveEverything();
        deleteUselessObject();
        draw();
    }
}

Game::Game() {
    srand(time(NULL));
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
    //player = std::make_unique<Soldier>(settings.shipSize,settings.shipPosition,settings.normalBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed);
    //player = std::make_unique<Snake>(settings.shipSize,settings.shipPosition,settings.curlyBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed,settings.playerCurlyBulletWidth);
    player = std::make_unique<LaserMan>(settings.shipSize,settings.shipPosition,settings.laserSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.laserPlayerTime);
}

void Game::enemyShoot() {
    if(enemyShootTimer.getElapsedTime().asSeconds()>settings.enemyShoot){
        auto ptr = std::next(chickens.begin(),rand()%chickens.size());
        chickenBullets.push_back(ptr->get()->shoot());
        enemyShootTimer.restart();
    }
}

void Game::deleteUselessObject() {
    deleteObjects<Bullet>(playerBullets);
    deleteObjects<Bullet>(chickenBullets);
    deleteObjects<Rock>(rocks);
    std::cout<<chickenBullets.size()<<" ";
    std::cout<<playerBullets.size()<<" ";
    std::cout<<rocks.size()<<std::endl;

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && playerShootTimer.getElapsedTime().asSeconds()>settings.playerShoot){
       playerBullets.push_back(player->shoot());
       playerShootTimer.restart();
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

template<typename object>
void Game::deleteObjects(std::list<std::unique_ptr<object>>& l){
    std::vector<decltype(l.begin())> pb; //delete player bullets
    for(auto ptr = l.begin(); ptr!=l.end(); ptr++)
        if(!ptr->get()->isAlive())
            pb.push_back(ptr);
    for(auto bullet : pb)
        l.erase(bullet);
}

void Game::addEnemy() {
    if(addEnemyTimer.getElapsedTime().asSeconds()<settings.enemyAppearTime)
        return;
    addEnemyTimer.restart();
    short r = rand()%4;
    sf::Vector2f pos{rand()%1000+100,-100};
    switch (r) {
        case 0: // rock
            if(settings.maxRocksAmount>rocks.size())
                rocks.push_front(std::make_unique<Rock>(settings.rockSize,pos,settings.rockDmg,settings.rockSpeed,3.14/2));
            break;
        case 1: // normal chicken
            if(settings.maxChickensAmount>chickens.size())
                chickens.push_front(std::make_unique<Chicken>(settings.chickenSize,pos,settings.normalBulletSize,settings.chickenHp,settings.chickenDmg,settings.chickenBulletSpeed,settings.area));
            break;
        case 2: // big chicken
            if(settings.maxChickensAmount>chickens.size())
                chickens.push_front(std::make_unique<Chicken>(settings.bigChickenSize,pos,settings.normalBulletSize,settings.bigChickenHp,settings.bigChickenDmg,settings.bigChickenBulletSpeed,settings.area));
            break;
        case 3: // alien
            if(settings.maxChickensAmount>chickens.size())
                chickens.push_front(std::make_unique<Alien>(settings.alienSize,pos,settings.laserSize,settings.alienHp,settings.alienDmg,settings.alienBulletTime,settings.alienShootTime,settings.area,rand()%(int)settings.area.y+20));
            break;
    }
}