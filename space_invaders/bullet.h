#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet : public Sprite {
public:
	static void Update(const float& dt);
	static void Render(RenderWindow& window);
	static void Fire(const Vector2f& pos, const bool mode);
	~Bullet() = default;
protected:
	static unsigned char bulletPointer;
	static Bullet bullets[256];
	void _Update(const float& dt);
	Bullet();
	//player bullet = false, enemy bullet = true
	bool _mode;
};