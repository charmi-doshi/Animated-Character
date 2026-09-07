#pragma once
#include <SDL3/SDL.h>

class IDrawable {
public:
	virtual ~IDrawable() = default;
	virtual void render(SDL_Renderer* renderer) const = 0;
};
