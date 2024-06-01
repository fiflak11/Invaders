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
    sf::Vector2f normalBulletSize{3,3};
};

#endif //INVADERS_SETTINGS_H
