#include "player.h"
using namespace sf;
using namespace std;

void Player::Update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Left))
		move(Vector2f(-0.1f, 0.0f));
	if (Keyboard::isKeyPressed(Keyboard::Right))
		move(Vector2f(0.1f, 0.0f));
	if (Keyboard::isKeyPressed(Keyboard::Up))
		move(Vector2f(0.0f, -0.1f));
	if (Keyboard::isKeyPressed(Keyboard::Down))
		move(Vector2f(0.0f, 0.1f));

	Entity::Update(dt);
}

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.0f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.0f, 25.0f));
}

void Player::Render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}