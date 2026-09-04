#pragma once
#include<SDL3/SDL.h>

class Animator {

private:
	SDL_Color* tints_;
	int frameCount_;
	float frameDuration_;
	int currentFrame_;
	float accumulator_;


public:
	Animator(int frameCount, float frameDuration);
	~Animator();

	Animator(const Animator&) = delete;
	Animator& operator = (const Animator&) = delete;

	void update(float dt);

	SDL_Color currentTint() const;
	int currentFrame() const { return currentFrame_; }

};
