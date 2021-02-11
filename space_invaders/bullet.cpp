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
	;
}

unsigned char Bullet::bulletPointer;
Bullet Bullet::bullets[256];