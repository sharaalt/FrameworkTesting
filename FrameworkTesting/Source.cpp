#include <iostream>
#include "steam/steam_api.h"
#include "SDL3/SDL.h"
#include "GameObject.hpp"

static float deltaTime(Uint64 &lastTime) {
    Uint64 currentTime = SDL_GetTicks();
    float dt = (float)(currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    return dt;
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_EVENTS);

    if (SteamAPI_RestartAppIfNecessary(480)) {
        return 1;
    }

    if (!SteamAPI_Init()) {
        std::cout << "Steamworks failed to initialize! (Is Steam running?)" << std::endl;
        return 1;
    }

    SDL_FRect rect;
    rect.x = 10;
    rect.y = 10;
    rect.h = 50;
    rect.w = 50;



    Vector2 position = { 2,2 };
    GameObject obj = GameObject(position, rect );

    bool shouldRender = true;

    SDL_Window* window = SDL_CreateWindow("Window", 500, 500, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderVSync(renderer, 1);

    SDL_Event event;

    float speed = 300;

    Uint64 lastTime = SDL_GetTicks();

    while (shouldRender) {
        SteamAPI_RunCallbacks();

        float dt = deltaTime(lastTime);
        const bool* key_states = SDL_GetKeyboardState(NULL);

        Vector2 directionVector;
        
        if (key_states[SDL_SCANCODE_W]) directionVector.y -= 1;
        if (key_states[SDL_SCANCODE_S]) directionVector.y += 1;
        if (key_states[SDL_SCANCODE_A]) directionVector.x -= 1;
        if (key_states[SDL_SCANCODE_D]) directionVector.x += 1;

        obj.Update(directionVector, dt);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                shouldRender = false;
                return 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        obj.Render(renderer);

        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SteamAPI_Shutdown();
    return 0;
}