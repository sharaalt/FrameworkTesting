#include <iostream>
#include "steam/steam_api.h"
#include "SDL3/SDL.h"
#include "CameraObject.hpp"
#include "PlayerObject.hpp"
#include <Windows.h>

constexpr int WINDOW_WIDTH = 500;
constexpr int WINDOW_HEIGHT = 500;
constexpr int STEAM_APP_ID = 480;

// Calculates deltaTime based on current and last frame times.
static float deltaTime(Uint64 &lastTime) {
    Uint64 currentTime = SDL_GetTicks();
    float dt = (float)(currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    return dt;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_EVENTS);

    // Checks if the .exe was ran through steam if not restart it.
    if (SteamAPI_RestartAppIfNecessary(STEAM_APP_ID)) {
        return 1;
    }

    // If steam isn't active on the tray the error will be thrown.
    if (!SteamAPI_Init()) {
        std::cout << "Steamworks failed to initialize! (Is Steam running?)" << std::endl;
        return 1;
    }

    SDL_Rect rect2;
    rect2.x = 0;
    rect2.y = 0;
    rect2.h = 250;
    rect2.w = 250;

    SDL_FRect rect;
    rect.x = 10;
    rect.y = 10;
    rect.h = 50;
    rect.w = 50;

    // Initalizes the cameraObject using rect2
    CameraObject cam = CameraObject(rect2);
    Vector2 position;

    // Initalizes the playerObject by using rect1
    PlayerObject obj = PlayerObject(position, rect);

    bool shouldRender = true;

    // Initalizes the window and renderer object
    SDL_Window* window = SDL_CreateWindow("Window", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderVSync(renderer, 1);

    SDL_Event event;

    float speed = 300;

    // Tracks the last frame time
    Uint64 lastTime = SDL_GetTicks();
    int newW = WINDOW_WIDTH;  
    int newH = WINDOW_HEIGHT;

    // Main loop
    while (shouldRender) {
        SteamAPI_RunCallbacks();
        float dt = deltaTime(lastTime);
        Vector2 wh = { (float)newW, (float)newH };

        // Checks for non-input events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) shouldRender = false;

            if (event.type == SDL_EVENT_WINDOW_RESIZED) {
                newW = event.window.data1;
                newH = event.window.data2;

                cam.SetSize((float)newW, (float)newH);
            }
        }

        Vector2 directionVector;

        // Checks for input
        const bool* key_states = SDL_GetKeyboardState(NULL);
        if (key_states[SDL_SCANCODE_W]) directionVector.y -= 1;
        if (key_states[SDL_SCANCODE_S]) directionVector.y += 1;
        if (key_states[SDL_SCANCODE_A]) directionVector.x -= 1;
        if (key_states[SDL_SCANCODE_D]) directionVector.x += 1;
        if (key_states[SDL_SCANCODE_LSHIFT]) {
            directionVector.y *= 5; 
            directionVector.x *= 5;
        }

        // Placeholder Rectangle
        SDL_FRect a = cam.GetRenderRect(rect);

        obj.Update(directionVector, dt);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &a);

        cam.Update(obj.GetPosition(), wh, dt);

        obj.Render(renderer, cam);

        SDL_RenderPresent(renderer);
    }
    
    // Clean's up the renderer and window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SteamAPI_Shutdown();
    return 0;
}