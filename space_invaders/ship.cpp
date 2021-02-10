#include "ship.h"
#include "game.h"

using namespace sf;
using namespace std;

//****Ship****
Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::Update(const float& dt) {}

Ship::~Ship() = default;

//****Invader****
Invader::Invader() : Ship() {}

Invader::Invader(IntRect ir, Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);
}