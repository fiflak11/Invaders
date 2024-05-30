#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(settings.displayResolution[0].first, settings.displayResolution[0].second), "Invaders");
    window.setFramerateLimit(60);
}

void Game::start() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}