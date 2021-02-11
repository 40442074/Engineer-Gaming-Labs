#include "bullet.h"
#include "game.h"

using namespace std;

Bullet::Bullet() {}

void Bullet::Update(const float& dt) {
	;
}

void Bullet::Render(RenderWindow& window) {
	for (Bullet b : Bullet::bullets) {
		window.draw(b);
	}
}

void Bullet::Fire(const Vector2f& pos, const bool mode) {
	auto b = &bullets[bulletPointer++];
	b->setPosition(pos);
	b->_mode = mode;
}

void Bullet::_Update(const float& dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		return;
	}
	else {
		move(0, dt * 200.0f * (_mode ? 1.0f : - 1.0f));
		const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships) {
			if (!_mode && typeid(s) == typeid(Player)) {
				continue;
			}
			if (_mode && typeid(s) != typeid(Player)) {
				continue;
			}
			if (!s->is_exploded() && s->getGlobalBounds().intersects(boundingBox)) {
				s->Explode();
				setPosition(-100, -100);
				return;
			}
		}
	}
}

unsigned char Bullet::bulletPointer;
Bullet Bullet::bullets[256];