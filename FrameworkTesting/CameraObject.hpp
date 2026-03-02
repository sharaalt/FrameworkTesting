#ifndef CAMERA_OBJECT_HPP
#define CAMERA_OBJECT_HPP

#include "Definitions.hpp"
#include <SDL3/SDL.h>

class CameraObject {
	public:
		CameraObject(SDL_Rect rect);
		void SetSize(float width, float height);
		void Update(const Vector2& position, const Vector2& wh, float dt);
		SDL_FRect GetRenderRect(const SDL_FRect& worldRect);
		float Lerp(float startValue, float endValue, float time);
	private:
		Vector2 camPosition;
		SDL_Rect cameraRect;
};

#endif // CAMERA_OBJECT_HPP