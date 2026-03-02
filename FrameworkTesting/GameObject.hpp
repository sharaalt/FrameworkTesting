#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL3/SDL.h>
#include "Definitions.hpp"
#include "CameraObject.hpp"

class GameObject {
	public:
		GameObject(const Vector2& pos, SDL_FRect rect);
		Vector2 GetPosition();
		Vector2 GetVelocity();
		void SetPosition(const Vector2& position);
		virtual void Update(Vector2 input, float dt) = 0;		
		void Render(SDL_Renderer* renderer, CameraObject& camera);
	protected:
		Vector2 position;
		Vector2 velocity;
		SDL_FRect rect;
};


#endif // GAME_OBJECT_HPP
