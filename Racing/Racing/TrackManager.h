#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>

#include "Player.h"

using namespace sf;
using namespace std;

class TrackManager
{
public:
	Mouse mouse;
	vector<Vector2f> outerTrackPoints;
	vector<Vector2f> innerTrackPoints;
	vector<Vector2i> goal;

	bool makingOuter = true;
	bool makingTrack = true;
	bool makingInner = false;
	bool placingPlayer = true;

	
	void placePoint()
	{
		if(makingTrack)
		{
			Vector2i pointPos = mouse.getPosition();
			Vector2f mousePos = Vector2f(pointPos);

			if (makingInner)
			{
				innerTrackPoints.push_back(mousePos);
			}

			else if(makingOuter)
			{
				outerTrackPoints.push_back(mousePos);
			}	
		}
	}

	void placeGoal()
	{
		if(makingTrack)
		{
			Vector2i mousePos = mouse.getPosition();
			for(int i = 0; i < innerTrackPoints.size();i++)
			{
				float len = sqrt(pow(mousePos.x - innerTrackPoints[i].x, 2) - pow(mousePos.y - innerTrackPoints[i].y, 2));
				if (len < 10)
				{
					Vector2i point(mousePos.x, mousePos.y);
					goal.push_back(point);
				}
			}
		}
	}

	void placePlayerSpawn(Player &player)
	{
		if(!makingTrack && placingPlayer)
		{
			player.position.x = mouse.getPosition().x;
			player.position.y = mouse.getPosition().y;
		}
	}
};