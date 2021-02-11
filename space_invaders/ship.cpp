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

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 0; i < ships.size(); i++) {
			ships[i]->MoveDown();
		}
	}
}

void Invader::MoveDown()
{
	move(0, 24);
}

bool Invader::direction = true;
float Invader::speed = 20.0f;

//****Player****
Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setOrigin(16, 16);
	setPosition({ gameWidth * 0.5f, gameHeight - 32.0f });
}

void Player::Update(const float& dt) {
	Ship::Update(dt);

	if (Keyboard::isKeyPressed(controls[0])) {
		move(dt * -100.0f, 0);		
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		move(dt * 100.0f, 0);
	}

	if (getPosition().x > gameWidth - 16) {
		setPosition(gameWidth - 16, getPosition().y);
	}
	if (getPosition().x < 16) {
		setPosition(16, getPosition().y);
	}
}