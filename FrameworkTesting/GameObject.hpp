#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL3/SDL.h>
#include "Definitions.hpp"

class GameObject {
	public:
		GameObject(const Vector2& pos, SDL_FRect rect);
		Vector2 GetPosition();
		Vector2 GetVelocity();
		void SetPosition(Vector2 position);
		void Update(Vector2 velocity, float dt);
		void Render(SDL_Renderer* renderer);
	private:
		Vector2 position;
		Vector2 velocity;
		SDL_FRect rect;
};


#endif // GAME_OBJECT_HPP
