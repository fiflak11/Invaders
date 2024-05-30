#ifndef INVADERS_SETTINGS_H
#define INVADERS_SETTINGS_H

#include <array>
#include <utility>
#include <string>

struct Settings{
    std::array<std::pair<short,short>,2> displayResolution = {{{1280,720}}}; //probably more in the future
    std::array<std::string,3> level = {"easy","medium","hard"};

};

#endif //INVADERS_SETTINGS_H
