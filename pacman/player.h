#pragma once
#include "entity.h"

class Player : public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	Player();
	void QueueForRender() const override;
};