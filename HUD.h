#pragma once
#include <SDL3/SDL.h>
#include "IUpdatable.h"
#include "IDrawable.h"

class HUD :public IUpdatable, public IDrawable {
public:
	explicit HUD(int sampleCount = 60);
	~HUD() override;

	HUD(const HUD&) = delete;
	HUD& operator = (const HUD&) = delete;

	void update(float dt) override;
	void render(SDL_Renderer* renderer) const override;
	float smoothedFps() const;
	
private:
	float* samples_; 
	int sampleCount_;
	int nextIndex_;
	int filledCount_;
};