#include "GameObject.hpp"
#include <iostream>;

GameObject::GameObject(const Vector2& pos, SDL_FRect rect) : position(pos), rect(rect), velocity({0,0}) {}

Vector2 GameObject::GetPosition() {
	return this->position;
}

Vector2 GameObject::GetVelocity() {
	return this->velocity;
}

void GameObject::SetPosition(Vector2 position) {
	this->rect.x = position.x;
	this->rect.y = position.y;
}

void GameObject::Update(Vector2 vel, float dt) {
	float friction = SDL_powf(0.95f, dt);
	float maxSpeed = 500.0f;

	SDL_clamp(vel.x, 0, maxSpeed);
	SDL_clamp(vel.y, 0, maxSpeed);

	this->velocity.x *= friction;
	this->velocity.y *= friction;

	this->position.x += vel.x * dt;
	this->position.y += vel.y * dt;

	this->velocity = vel;

	this->SetPosition(this->position);
}

void GameObject::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}