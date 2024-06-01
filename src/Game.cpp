#include "Game.h"
#include "Player/Player.h"
#include "Player/Soldier.h"
#include "Player/LaserMan.h"
#include "Player/Snake.h"
#include <memory>

void Game::start() {
    while (window.isOpen())
    {
        events();
        playerMove();
        draw();
    }
}

Game::Game() {
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
    player = std::make_unique<LaserMan>(settings.shipSize,settings.shipPosition,20,2,2,2);
}

void Game::playerMove() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player->move('r',settings.displayResolution[0].first);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player->move('l',settings.displayResolution[0].first);
    else
        player->move('n',settings.displayResolution[0].first);
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
    window.draw(player->getRect());
    window.display();
}