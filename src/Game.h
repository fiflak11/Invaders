#ifndef INVADERS_GAME_H
#define INVADERS_GAME_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

class Game {
    sf::RenderWindow window;
    const Settings settings;
    public:
    Game();
    void start();
};

#endif //INVADERS_GAME_H
