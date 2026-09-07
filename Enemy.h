#pragma once
#include "Entity.h"

class Enemy :public Entity {
public :
	Enemy(float startX, float startY, float width, float height, float speed, float screenWidth, SDL_Color baseColor);

	void update(float dt) override;
	void render(SDL_Renderer* renderer) const override;

private:
	float     speed_;
	float     screenWidth_;
	SDL_Color baseColor_;
};
