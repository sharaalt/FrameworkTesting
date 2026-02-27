#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SDL3/SDL.h>

struct Vector2 {
	float x;
	float y;
};

class GameObject {
	public:
		GameObject(const Vector2& pos, SDL_FRect rect);
		Vector2 GetPosition();
		void SetPosition(int x, int y);
		void Render(SDL_Renderer* renderer);
	private:
		Vector2 position;
		SDL_FRect rect;
};


#endif // GAME_OBJECT_HPP
