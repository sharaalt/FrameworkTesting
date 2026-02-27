#include <SDL3/SDL.h>

struct Vector2 {
    float x = 0.0f;
    float y = 0.0f;

    float Magnitude() const {
        return SDL_sqrtf(static_cast<float>((x * x) + (y * y)));
    }
};