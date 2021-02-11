#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ship : public Sprite {
protected:
	IntRect _sprite;
	Ship();
	bool _exploded = false;
public:
	explicit Ship(IntRect ir);
	virtual ~Ship() = 0;
	virtual void Update(const float& dt);
	virtual void MoveDown() {}
	bool is_exploded() const;
	virtual void Explode();
};

class Invader : public Ship {
public:
	static bool direction;
	static float speed;

	Invader(IntRect ir, Vector2f pos);
	Invader();
	void Update(const float& dt) override;
	void MoveDown() override;
};

class Player : public Ship {
public:
	Player();
	void Update(const float& dt) override;
};