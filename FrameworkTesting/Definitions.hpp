#ifndef DEFINITIONS_HPP 
#define DEFINITIONS_HPP 

#include <cmath>

struct Vector2 {
    float x = 0.0f;
    float y = 0.0f;

    float Magnitude() const {
        return std::sqrt(((x * x) + (y * y)));
    }
};

#endif // DEFINITIONS_HPP