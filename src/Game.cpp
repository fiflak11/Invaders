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
        playerIntersectWithObjects();
        chickenIntersectWithObjects();
        deleteUselessObject();
        statsUpdate();
        draw();
        while(player->getHp()<=0)
            zeroHp();
    }
}

Game::Game() {
    srand(time(NULL));
    latoBlack.loadFromFile("../Fonts/Lato-Black.ttf");
    stats.setFont(latoBlack);
    stats.setPosition(20,670);
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
    shipChoice();
}

void Game::zeroHp() {
    chickens.clear();
    rocks.clear();
    playerBullets.clear();
    chickenBullets.clear();
    points=0;
    sf::Text restart;
    restart.setFont(latoBlack);
    restart.setString("RESTART");
    restart.setPosition(500,300);
    auto pos = restart.getGlobalBounds();
    while(player->getHp()<0){
        events();
        window.clear();
        window.draw(stats);
        sf::Mouse e;
        auto w = sf::Mouse::getPosition(window);
        window.draw(restart);
        window.display();
        if(e.isButtonPressed(sf::Mouse::Left) && pos.contains(w.x,w.y)){
            shipChoice();
            break;
        }
    }
}

void Game::shipChoice(){
    std::cout<<"CIPA";
    auto player1 = std::make_unique<Soldier>(settings.shipSize,sf::Vector2f(200,350),settings.normalBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed);
    auto player2 = std::make_unique<Snake>(settings.shipSize,sf::Vector2f(600,350),settings.curlyBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed,settings.playerCurlyBulletWidth);
    auto player3 = std::make_unique<LaserMan>(settings.shipSize,sf::Vector2f(1000,350),settings.laserSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.laserPlayerTime);
    auto rectp1 = player1->getRect().getGlobalBounds();
    auto rectp2 = player2->getRect().getGlobalBounds();
    auto rectp3 = player3->getRect().getGlobalBounds();
    while(true){
        events();
        window.clear();
        window.draw(player1->getRect());
        window.draw(player2->getRect());
        window.draw(player3->getRect());
        auto w = sf::Mouse::getPosition(window);
        sf::Mouse e;
        if(e.isButtonPressed(sf::Mouse::Left))
        {
            if (rectp1.contains(w.x, w.y))
                player = std::make_unique<Soldier>(settings.shipSize,settings.shipPosition,settings.normalBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed);
            else if (rectp2.contains(w.x, w.y))
                player = std::make_unique<Snake>(settings.shipSize,settings.shipPosition,settings.curlyBulletSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.playerBulletSpeed,settings.playerCurlyBulletWidth);
            else if (rectp3.contains(w.x, w.y))
                player = std::make_unique<LaserMan>(settings.shipSize,settings.shipPosition,settings.laserSize,settings.playerMaxSpeed,settings.playerAcceleration,settings.playerHp,settings.playerDmg,settings.laserPlayerTime);
            if(player != nullptr && player->getHp()>0)
                break;
        }
        window.display();
    }
}

void Game::playerIntersectWithObjects(){
    std::vector<decltype(chickenBullets.begin())> cb;
    for(auto ptr = chickenBullets.begin(); ptr!=chickenBullets.end(); ptr++)
        if(player->getRect().getGlobalBounds().intersects(ptr->get()->getRect().getGlobalBounds())){
            player->getShot(ptr->get()->getDmg());
            cb.push_back(ptr);
        }
    for(auto bullet : cb)
        chickenBullets.erase(bullet);
    std::vector<decltype(rocks.begin())> r;
    for(auto ptr = rocks.begin(); ptr!=rocks.end(); ptr++)
        if(player->getRect().getGlobalBounds().intersects(ptr->get()->getRect().getGlobalBounds())){
            player->getShot(ptr->get()->getDmg());
            r.push_back(ptr);
        }
    for(auto bullet : r)
        rocks.erase(bullet);
}

void Game::chickenIntersectWithObjects() {
    std::vector<decltype(playerBullets.begin())> pb;
    std::vector<decltype(chickens.begin())> c;
    for(auto ptr1 = playerBullets.begin(); ptr1!=playerBullets.end(); ptr1++){
        for(auto ptr2 = chickens.begin(); ptr2!=chickens.end(); ptr2++){
            if(ptr1->get()->getRect().getGlobalBounds().intersects(ptr2->get()->getRect().getGlobalBounds())){
                pb.push_back(ptr1);
                ptr2->get()->getShot(ptr1->get()->getDmg());
                if(ptr2->get()->getHp()<=0)
                    c.push_back(ptr2);
            }
        }
    }
    for(auto x : pb)
        playerBullets.erase(x);
    for(auto x : c)
        chickens.erase(x);
    points+=c.size()*10;
}

void Game::statsUpdate() {
    stats.setString("HP: " + std::to_string(player->getHp()) + "/" +std::to_string(player->maxHp)+"   POINTS: "+std::to_string(points));
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
    window.draw(stats);
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
    //zadbaj o laser

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