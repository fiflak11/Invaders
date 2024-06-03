#ifndef INVADERS_GAME_H
#define INVADERS_GAME_H

#include <list>
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

class Game {
    sf::RenderWindow window;
    const Settings settings;
    std::unique_ptr<Player> player;
    std::list<std::unique_ptr<Enemy>> chickens;
    std::list<std::unique_ptr<Bullet>> playerBullets;
    std::list<std::unique_ptr<Bullet>> chickenBullets;
    void playerMoveAndShoot();
    void events();
    void draw();
    void bulletsMove();
    public:
    Game();
    void start();
};

#endif //INVADERS_GAME_H
