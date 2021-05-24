#pragma once

#include <SFML/System/Vector2.hpp>
#include "TimeManager.h"

using namespace sf;

class Player
{
public:
	Player(TimeManager& TimeManager);

	void Update();


	Vector2f GetPosition() { return position; }

private:

	TimeManager* timeManager;
	Vector2f position;
	float movementSpeed = 2;
};

