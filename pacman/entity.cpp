#include "entity.h"

using namespace std;
using namespace sf;

const Vector2f Entity::getPosition() { return _position; }

void Entity::setPosition(const Vector2f& pos) { _position = pos; }

void Entity::move(const Vector2f& pos) { _position += pos; }

void Entity::Update(const double dt) {
	_shape->setPosition(_position);
}

Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}

void EntityManager::update(double dt) {
	for (int i = 0; i < list.size(); i++)
		list[i].get()->Update(dt);
}

void EntityManager::render() {
	for (int i = 0; i < list.size(); i++)
		list[i].get()->QueueForRender();
	Renderer::render();
}