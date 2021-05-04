#include "ghost.h"
#include <iostream>
#include "time.h"

using namespace sf;
using namespace std;

void Ghost::Update(double dt) {
	if (_randomTimer <= 0)
	{
		cout << "ghost dir switch";

		srand(time(NULL));
		auto choice = rand() % 4;

		switch (choice)
		{
		case 0: _dir = Vector2f(-0.1f, 0.0f); break;
		case 1: _dir = Vector2f(0.1f, 0.0f); break;
		case 2: _dir = Vector2f(0.0f, -0.1f); break;
		case 3: _dir = Vector2f(0.0f, 0.1f); break;
		}

		_randomTimer = MOVEINTERVAL;
	}

	move(_dir);

	_randomTimer -= dt;

	Entity::Update(dt);
}

Ghost::Ghost() : _speed(200.0f), Entity(make_unique<CircleShape>(25.0f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.0f, 25.0f));
}

void Ghost::QueueForRender() const {
	Renderer::queue(&*_shape);
}