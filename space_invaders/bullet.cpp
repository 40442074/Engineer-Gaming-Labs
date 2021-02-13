#include "bullet.h"
#include "game.h"

using namespace std;

Bullet::Bullet() {}

void Bullet::Update(const float& dt) {
	for (auto& b : Bullet::bullets) {
		b._Update(dt);
	}
}

void Bullet::Render(RenderWindow& window) {
	for (const auto b : Bullet::bullets) {
		window.draw(b);
	}
}

void Bullet::Fire(const Vector2f& pos, const bool mode, IntRect ir) {
	auto b = &bullets[bulletPointer++];
	b->setPosition(pos);
	b->_mode = mode;

	b->_sprite = ir;
	b->setTexture(spritesheet);
	b->setTextureRect(b->_sprite);
	b->setOrigin(16, 16);
}

void Bullet::_Update(const float& dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		return;
	}
	else {
		move(0, dt * 200.0f * (_mode ? 1.0f : - 1.0f));
		const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships) {
			if (!_mode && s->is_player()) {
				continue;
			}
			if (_mode && !s->is_player()) {
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