#pragma once
#include <SDL3/SDL.h>
#include "Animator.h"

class Entity
{
public:
    Entity(float x, float y,
        float width, float height,
        int   frameCount = 6,
        float frameDuration = 1.0f / 8.0f);

    ~Entity() = default;

    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    void update(float dt);
    void render(SDL_Renderer* renderer) const;

protected:
    Animator animator_;
    float    x_, y_;
    float    width_, height_;
};