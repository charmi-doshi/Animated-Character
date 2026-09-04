#pragma once
#include <SDL3/SDL.h>
#include "Animator.h"

class Player {
public:
    Player(float screenWidth, float screenHeight,
        int   frameCount = 6,
        float frameDuration = 1.0f / 8.0f);
    
    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    void update(float dt);
    void render(SDL_Renderer* renderer) const;
private:
    Animator animator_;
    float x_, y_;
    float width_, height_;

};
