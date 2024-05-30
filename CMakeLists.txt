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
        src/Bullet/Bomb.h)

target_link_libraries(Invaders sfml-graphics)