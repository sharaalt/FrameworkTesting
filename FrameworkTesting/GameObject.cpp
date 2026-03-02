#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(const Vector2& pos, SDL_FRect rect) : position(pos), rect(rect), velocity({0,0}) {}

// Gets the position of the object
Vector2 GameObject::GetPosition() {
	return this->position;
}

// Gets the velocity of the object
Vector2 GameObject::GetVelocity() {
	return this->velocity;
}

// Sets the position of the object
void GameObject::SetPosition(const Vector2& position) {
	this->rect.x = position.x;
	this->rect.y = position.y;
}

// Renders the object and coverts it from window to world space
void GameObject::Render(SDL_Renderer* renderer, CameraObject& camera) {
	SDL_FRect screenRect = camera.GetRenderRect(this->rect);
		
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &screenRect);
}