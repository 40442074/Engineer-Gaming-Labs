#pragma once
#include <SFML/Graphics.hpp>
#include "ship.h"

using namespace sf;

constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_columns = 12;

const Keyboard::Key controls[3] = {
    Keyboard::Left,
    Keyboard::Right,
    Keyboard::Space
};

extern Texture spritesheet;
extern std::vector<Ship*> ships;