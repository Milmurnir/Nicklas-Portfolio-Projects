#pragma once

#include <Windows.h>
#include <math.h>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;
using namespace std;

class Player
{
public:

	int id = 0;
	Vector2f position;
	int sizeX = 10;
	int sizeY = 20;

	float velocity = 0;
	float maxVelocity = 0.25;
	float acceleration = 0.0001f;

	float rotation = 0;
	float rotationSpeed = 0.1;

	bool playerHit = false;
	
	float lastX = position.x;
	float lastY = position.y;

	Color color = Color::Red;


	void checkMovement(bool placingPlayer)
	{
		int right = 'D';
		int left = 'A';
		int up = 'W';
		int down = 'S';

		float xHeading,yHeading;

		if(!placingPlayer)
		{
			if(rotation > 360)
			{
				rotation = 0;
			}

			else if(rotation < 0)
			{
				rotation = 360;
			}

			if(velocity != 0)
			{
				if (GetKeyState(right) & 0x8000)
				{
					rotation += rotationSpeed;
				}

				else if (GetKeyState(left) & 0x8000)
				{
					rotation -= rotationSpeed;
				}
			}

			float rad = rotation * 3.14 / 180;
			xHeading = cos(rad);
			yHeading = sin(rad);

			lastX = position.x;
			lastY = position.y;

			position.x += xHeading * velocity;
			position.y += yHeading * velocity;

			if (GetKeyState(up) & 0x8000)
			{
				if(velocity < maxVelocity)
				{
					velocity += acceleration;
				}
			}

			else
			{
				if(velocity > 0)
				{
					if(velocity > 0.01f)
					{
						velocity -= acceleration;
					}

					else
					{
						velocity = 0;
					}
					
				}
			}
				
			if(GetKeyState(down) & 0x8000)
			{
				if(velocity > -maxVelocity)
				{
					velocity -= acceleration;
				}
				
			}

			else
			{
				if(velocity < 0)
				{
					velocity += acceleration;
				}
			}

		}
	}
};