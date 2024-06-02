#ifndef INVADERS_SETTINGS_H
#define INVADERS_SETTINGS_H

#include <SFML/Graphics.hpp>
#include <array>
#include <utility>
#include <string>

struct Settings{
    std::array<std::pair<short,short>,2> displayResolution = {{{1280,720}}}; //probably more in the future
    std::array<std::string,3> level = {"easy","medium","hard"};
    sf::Vector2f shipSize{50,50};
    sf::Vector2f shipPosition{displayResolution[0].first/2, displayResolution[0].second-shipSize.y-shipSize.y};
    sf::Vector2f normalBulletSize{3,3}; //BULLET SIZE
    sf::Vector2f curlyBulletSize{10,10};
    sf::Vector2f laserSize{5,2000};
    short playerMaxSpeed=20;
    short playerAcceleration=2;
    short playerHp=100;
    short playerDmg=10;
    short laserPlayerTime=10;
    short playerBulletSpeed=4;
    short playerCurlyBulletWidth=4;
};

#endif //INVADERS_SETTINGS_H
