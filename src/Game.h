#ifndef INVADERS_GAME_H
#define INVADERS_GAME_H

#include <list>
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Enemy/Rock.h"

class Game {
    sf::Clock addEnemyTimer, playerShootTimer, enemyShootTimer;
    sf::RenderWindow window;
    const Settings settings;
    std::unique_ptr<Player> player;
    std::list<std::unique_ptr<Enemy>> chickens;
    std::list<std::unique_ptr<Rock>> rocks;
    std::list<std::unique_ptr<Bullet>> playerBullets;
    std::list<std::unique_ptr<Bullet>> chickenBullets;
    void playerMoveAndShoot();
    void events();
    template<typename object>
    void drawList(std::list<std::unique_ptr<object>>& l); //draw list of object
    template<typename object>
    void moveList(std::list<std::unique_ptr<object>>& l); //draw list of object
    void moveEverything();
    void draw();
    void addEnemy();
    void deleteUselessObject();
    void enemyShoot();
    public:
    Game();
    void start();
};

#endif //INVADERS_GAME_H
