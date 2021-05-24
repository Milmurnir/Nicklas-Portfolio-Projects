#pragma once

#include <SFML/Graphics.hpp>
#include "TrackManager.h"

using namespace sf;

class InputManager
{
public:

	RenderWindow* window;
	TrackManager* trackManager;
	Event event;

	InputManager(RenderWindow &_window,TrackManager &_trackManager)
	{
		window = &_window;
		trackManager = &_trackManager;
	}

	void update()
	{
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
			}


			//JUst checks if the user is clicking the lft mouse and places a point if its making track

			if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					trackManager->placePoint();
				}
			}

			//Checks if the user wants to keep making the track

			if (event.type == Event::KeyReleased)
			{
				if ((event.key.code == Keyboard::Enter) & !trackManager->makingInner)
				{
					trackManager->makingInner = true;
					trackManager->makingOuter = false;
				}

				else if (event.key.code == Keyboard::Enter)
				{
					trackManager->makingTrack = false;
					trackManager->makingInner = false;

				}
			}

			//Places the player

			if (event.type == Event::MouseButtonReleased)
			{
				if ((event.mouseButton.button == Mouse::Left) & trackManager->placingPlayer & !trackManager->makingTrack)
				{
					trackManager->placingPlayer = false;
				}
			}
		}
	}
};