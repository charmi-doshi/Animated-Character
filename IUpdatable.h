#pragma once

class IUpdatable {
public:
	virtual ~IUpdatable() = default;
	virtual void update(float dt) = 0;
};