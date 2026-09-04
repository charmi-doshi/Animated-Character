#include "HUD.h"

HUD::HUD(int sampleCount) :samples_(new float[sampleCount]), sampleCount_(sampleCount), nextIndex_(0),filledCount_(0)
{
	for (int i = 0; i < sampleCount_; i++) {
		samples_[i] = 0.0f;
	}
}

HUD::~HUD() {
	delete[] samples_;
}

void HUD::update(float dt) {
	samples_[nextIndex_] = dt;
	nextIndex_ = (nextIndex_ + 1) % sampleCount_;
	if (filledCount_ < sampleCount_) ++filledCount_;
}

float HUD::smoothedFps() const {
	if (filledCount_ == 0) return 0.0f;

	float sum = 0.0f;
	for (int i = 0; i < filledCount_; i++) {
		sum += samples_[i];
	}

	float avgDt = sum / (float)filledCount_;
	if (avgDt <= 0.0f) return 0.0f;
	return 1.0f / avgDt;
}