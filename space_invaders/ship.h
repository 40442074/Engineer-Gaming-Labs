#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ship : public Sprite {
protected:
	IntRect _sprite;
	Ship();
public:
	explicit Ship(IntRect ir);
	virtual ~Ship() = 0;
	virtual void Update(const float& dt);
};