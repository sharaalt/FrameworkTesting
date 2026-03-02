#include "PlayerObject.hpp"

PlayerObject::PlayerObject(const Vector2& pos, SDL_FRect rect) : GameObject(pos, rect) {};

// Handles players physics based off of input
void PlayerObject::Update(Vector2 vel, float dt) {
	this->velocity.x += vel.x * 500.0f * dt;
	this->velocity.y += vel.y * 500.0f * dt;

	float friction = SDL_powf(0.1f, dt);
	this->velocity.x *= friction;
	this->velocity.y *= friction;

	this->position.x += this->velocity.x * dt;
	this->position.y += this->velocity.y * dt;

	this->SetPosition(this->position);

	if (this->velocity.Magnitude() < 1.0f) { // Lower threshold for smoother stop
		this->velocity.x = 0.0f;
		this->velocity.y = 0.0f;
	}
}