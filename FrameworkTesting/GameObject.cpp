#include "GameObject.hpp"

GameObject::GameObject(const Vector2& pos, SDL_FRect rect) : position(pos), rect(rect) {}

Vector2 GameObject::GetPosition() {
	return position;
}

void GameObject::SetPosition(int x, int y) {
}

void GameObject::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}