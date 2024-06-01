#ifndef INVADERS_GAME_H
#define INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player/Player.h"

class Game {
    sf::RenderWindow window;
    const Settings settings;
    std::unique_ptr<Player> player;
    void playerMove();
    void events();
    void draw();
    public:
    Game();
    void start();
};

#endif //INVADERS_GAME_H
