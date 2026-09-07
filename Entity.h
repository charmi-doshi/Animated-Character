#pragma once
#include <SDL3/SDL.h>
#include "Animator.h"
#include "IUpdatable.h"
#include "IDrawable.h"

class Entity :public IUpdatable, public IDrawable
{
public:
    Entity(float x, float y,
        float width, float height,
        int   frameCount = 6,
        float frameDuration = 1.0f / 8.0f);

    

    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    void update(float dt) override;
    void render(SDL_Renderer* renderer) const override;

protected:
    Animator animator_;
    float    x_, y_;
    float    width_, height_;
};