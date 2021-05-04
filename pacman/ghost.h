#pragma once
#include "entity.h"

class Ghost : public Entity {
private:
	const float MOVEINTERVAL = 0.5f;
	float _speed;
	float _randomTimer = 0;
	sf::Vector2f _dir;

public:
	void Update(double dt) override;
	Ghost();
	void QueueForRender() const override;
};