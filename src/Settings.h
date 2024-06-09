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
    short maxChickensAmount = 10;
    short maxRocksAmount = 20;
    short playerMaxSpeed=20;
    short playerAcceleration=2;
    short playerHp=100;
    short playerDmg=10;
    short laserPlayerTime=2;
    short playerBulletSpeed=4;
    short playerCurlyBulletWidth=4;
    float enemyAppearTime = 0.1;
    float playerShoot = 0.2;
    float enemyShoot = 0.1;
    sf::Vector2f area{1280,400};
    //ROCK
    sf::Vector2f rockSize{10,10};
    short rockDmg = 5;
    short rockSpeed = 4;
    //chicken
    sf::Vector2f chickenSize{20,20};
    short chickenHp = 10;
    short chickenDmg = 1;
    short chickenBulletSpeed = 4;
    //big chicken
    sf::Vector2f bigChickenSize{50,50};
    short bigChickenHp = 20;
    short bigChickenDmg = 2;
    short bigChickenBulletSpeed = 3;
    //big chicken
    sf::Vector2f alienSize{10,10};
    short alienHp = 20;
    short alienDmg = 2;
    short alienBulletTime = 3;
    short alienShootTime = 60;
};

#endif //INVADERS_SETTINGS_H
