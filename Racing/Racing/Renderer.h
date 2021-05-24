#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Renderer
{
public:
	

	RectangleShape playerShape;
	RenderWindow* window;

	Renderer(Player player,RenderWindow &_window)
	{
		window = &_window;

		
		

		playerShape.setFillColor(Color::Red);
		playerShape.setSize(Vector2f(player.sizeX, player.sizeY));
		playerShape.setOrigin(player.sizeX / 2, player.sizeY / 2);
	}

	void draw(int id,int x,int y,float rotation)
	{
		if(id == 0)
		{
			playerShape.setPosition(x, y);
			playerShape.setRotation(rotation + 90);
			window->draw(playerShape);
		}

		else if(id == 1)
		{
			//Powerup!!
		}
	}

	void drawTrack(vector<Vector2f> outerTrackPoints, vector<Vector2f> innerTrackPoints)
	{
		vector<Vector2f> points; 

		for(int i = 0; i < 2;i++)
		{
			if(i != 0)
			{
				 points = outerTrackPoints;
			}
			
			else
			{
				points = innerTrackPoints;
			}

			for (int j = 0; j < points.size(); j++)
			{
				if (points.size() > 2)
				{
					if (j != points.size() - 1)
					{
						drawLine(points[j], points[j+1]);
					}

					else
					{
						drawLine(points[j], points[0]);
					}
				}
			}
		}
	}

	void drawLine(Vector2f p1,Vector2f p2)
	{
		Vertex line[] = { Vertex(Vector2f(p1.x,p1.y)),Vertex(Vector2f(p2.x,p2.y)) };
		window->draw(line, 2, Lines);
	}
};