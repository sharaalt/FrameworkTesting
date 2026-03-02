#ifndef PLAYER_OBJECT_HPP
#define PLAYER_OBJECT_HPP

#include "Definitions.hpp"
#include <SDL3/SDL.h>
#include "GameObject.hpp"

class PlayerObject : public GameObject {
	public:
		PlayerObject(const Vector2& pos, SDL_FRect rect);
		void Update(Vector2 velocity, float dt) override;
};

#endif // PLAYER_OBJECT_HPP