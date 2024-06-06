cmake_minimum_required(VERSION 3.27)
project(Invaders)

include(FetchContent)
set(BUILD_SHARED_LIBS  OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(Invaders src/main.cpp
        src/Settings.h
        src/Game.cpp
        src/Game.h
        src/Bullet/Bullet.cpp
        src/Bullet/Bullet.h
        src/Bullet/NormalBullet.cpp
        src/Bullet/NormalBullet.h
        src/Bullet/CurlyBullet.cpp
        src/Bullet/CurlyBullet.h
        src/Bullet/Bomb.cpp
        src/Bullet/Bomb.h
        src/Player/Player.cpp
        src/Player/Player.h
        src/Player/Soldier.cpp
        src/Player/Soldier.h
        src/Player/LaserMan.cpp
        src/Player/LaserMan.h
        src/Player/Snake.cpp
        src/Player/Snake.h
        src/Bullet/Laser.cpp
        src/Bullet/Laser.h
        src/Enemy/Enemy.cpp
        src/Enemy/Enemy.h
        src/Enemy/Chicken.cpp
        src/Enemy/Chicken.h
        src/Enemy/Alien.cpp
        src/Enemy/Alien.h
        src/Enemy/Rock.cpp
        src/Enemy/Rock.h)

target_link_libraries(Invaders sfml-graphics)