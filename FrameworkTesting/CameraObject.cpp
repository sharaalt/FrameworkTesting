#include "CameraObject.hpp"
#include <iostream>

CameraObject::CameraObject(SDL_Rect rect) : cameraRect(rect) {}

// Sets the size of the camera based off of width and height floats
void CameraObject::SetSize(float width, float height) {
    this->cameraRect.w = width;
    this->cameraRect.h = height;
}

// Updates the camera position based on the player position and screenSize
void CameraObject::Update(const Vector2& targetPosition, const Vector2& wh, float dt) {
    // Convert player position into world space with the wh
    float targetX = targetPosition.x - (wh.x / 2);
    float targetY = targetPosition.y - (wh.y / 2);

    float followSpeed = 5.0f;

    // When the player moves lerp to that position
    this->cameraRect.x = Lerp((float)this->cameraRect.x, targetX, followSpeed * dt);
    this->cameraRect.y = Lerp((float)this->cameraRect.y, targetY, followSpeed * dt);
}

// Converts a rectangles data into world space
SDL_FRect CameraObject::GetRenderRect(const SDL_FRect& worldRect) {
    return {
        worldRect.x - cameraRect.x,
        worldRect.y - cameraRect.y,
        worldRect.w,
        worldRect.h
    };
}

// Linearly interpolates an object between 2 points based on time
float CameraObject::Lerp(float startValue, float endValue, float time) {
    float interpolatedValue = startValue + time * (endValue - startValue);
    return interpolatedValue;
};