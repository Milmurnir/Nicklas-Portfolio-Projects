#pragma once

#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class CollisionManager
{
public:
	vector<Vector2f> trackColPoints;
	vector<Vector2f> playerColPoints;

	bool colTrackMade = false;
	int distanceBetweenPoints = 2;

	void givePoints(float x,float y, int sizeX,int sizeY,float rotation)
	{
		playerColPoints.clear();

		Vector2f p1;

		p1.x = x + sizeX * cos(rotation * 3.14 / 180) - -sizeY / 4 * sin(rotation * 3.14 / 180);
		p1.y = y + sizeX * sin(rotation * 3.14 / 180) + -sizeY / 4 * cos(rotation * 3.14 / 180);
		

		Vector2f p2;

		p2.x = x + sizeX * cos(rotation * 3.14 / 180) - sizeY / 4 * sin(rotation * 3.14 / 180);
		p2.y = y + sizeX * sin(rotation * 3.14 / 180) + sizeY / 4 * cos(rotation * 3.14 / 180);

		
		Vector2f p3;

		p3.x = x + -sizeX * cos(rotation * 3.14 / 180) - sizeY / 4 * sin(rotation * 3.14 / 180);
		p3.y = y + -sizeX * sin(rotation * 3.14 / 180) + sizeY / 4 * cos(rotation * 3.14 / 180);


		Vector2f p4;

		p4.x = x + -sizeX * cos(rotation * 3.14 / 180) - -sizeY / 4 * sin(rotation * 3.14 / 180);
		p4.y = y + -sizeX * sin(rotation * 3.14 / 180) + -sizeY / 4 * cos(rotation * 3.14 / 180);


		playerColPoints.push_back(p1);
		playerColPoints.push_back(p2);
		playerColPoints.push_back(p3);
		playerColPoints.push_back(p4);	
	}

	void checkColPlayer(vector<Vector2f> innerTrack, vector<Vector2f> outerTrack,Player &player,RenderWindow &window)
	{
		checkCollisionTrackPlayer(outerTrack,player,window);
		checkCollisionTrackPlayer(innerTrack,player,window);
	}

	void checkCollisionTrackPlayer(vector<Vector2f> points,Player &player,RenderWindow &window)
	{
		givePoints(player.position.x, player.position.y, player.sizeX, player.sizeY, player.rotation);

		if(points.size() > 0)
		{
			for (int i = 0; i < points.size(); i++)
			{
				Vector2f wV1;
				Vector2f wV0;

				if(i != points.size() - 1)
				{
					wV1 = points[i + 1] - points[i];
					wV0 = points[i];
				}

				else if(i == points.size() - 1)
				{
					wV1 = points[0] - points[i];
					wV0 = points[i];
				}


				for (int j = 0; j < playerColPoints.size(); j++)
				{
					Vector2f pV1;
					Vector2f pV0;
					
					if (j != playerColPoints.size() - 1)
					{
						pV1 = playerColPoints[j + 1] - playerColPoints[j];
						pV0 = playerColPoints[j];
					}
					
					else if (j == playerColPoints.size() - 1)
					{
						pV1 = playerColPoints[0] - playerColPoints[j];
						pV0 = playerColPoints[j];
					}

					float matrix[2][3];

					matrix[0][0] = pV1.x;
					matrix[0][1] = wV1.x;
					matrix[0][2] = pV0.x - wV0.x;

					matrix[1][0] = pV1.y;
					matrix[1][1] = wV1.y;
					matrix[1][2] = pV0.y - wV0.y;

					bool sol = false;
					sol = solve2DMatrix(matrix);
					
					
					if (sol)
					{
						if((matrix[0][2] < 0) & (matrix[0][2] > -1))
						{
							if((matrix[1][2] < 1) & (matrix[1][2] > 0))
							{
								Vector2f colPoint;
								colPoint.x = (wV0.x + wV1.x * matrix[1][2]);
								colPoint.y = (wV0.y + wV1.y * matrix[1][2]);
								
								Vector2f diff = player.position - colPoint;

								float diffMagnitude = sqrt(pow(player.position.x - colPoint.x, 2) + pow(player.position.y - colPoint.y, 2));

								Vector2f normal = diff / diffMagnitude;

								player.position += normal;

								break;
							} 
						}
					}
				}
			}
		}
	}

	bool solve2DMatrix(float matrix[2][3])
	{
		for(int i = 0; i < 2;i++)
		{
			if(matrix[i][i] == 0)
			{
				float temp[3];
				for(int j = 0;j < 3;j++)
				{
					temp[j] = matrix[0][j];
					matrix[0][j] = matrix[1][j];
					matrix[1][j] = temp[j];
				}
				for(int o = 0; o < 2;o++)
				{
					if(matrix[o][o] == 0)
					{
						return false;
					}
				}
			}
		}


		for (int col = 0; col < 2; col++)
		{
			for (int row = 0; row < 2; row++)
			{
				if (col != row)
				{
					float numSubtrations = (matrix[row][col] / matrix[col][col]);

					for (int o = 0; o < 3; o++)
					{
						//Thanks Toni for the help with this :))
						matrix[row][o] -= numSubtrations * matrix[col][o];
					}
				}
			}
		}
		for (int col = 0; col < 2; col++)
		{
			float division = matrix[col][col];
			for (int row = 0; row < 3; row++)
			{
				matrix[col][row] /= division;
			}
		}	
		
		return true;
	}
};