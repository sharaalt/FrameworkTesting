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
	this->velocity.x += vel.x * 500.0f* dt;
	this->velocity.y += vel.y * 500.0f * dt;
	
	float friction = SDL_powf(0.1f, dt);
	this->velocity.x *= friction;
	this->velocity.y *= friction;

	this->position.x += this->velocity.x * dt;
	this->position.y += this->velocity.y * dt;

	if (this->velocity.Magnitude() < 10.0f) {
		if (velocity.x and velocity.y == 0) return;

		velocity.x = 0; 
		velocity.y = 0;
	}

	this->SetPosition(this->position);
}

void GameObject::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}