#include <SFML/Graphics.hpp>

#include "TerrainManager.h"
#include "TimeManager.h"
#include "Player.h"
#include "Renderer.h"


using namespace sf;

int main()
{
	Event event;

	TimeManager timeManager;

	Player player(timeManager);

	TerrainManager terrainManager(player);

	Renderer renderer(terrainManager);



	while (renderer.GetDisplay()->isOpen())
	{
		timeManager.StartTimer();

		player.Update();

		terrainManager.Update();

		renderer.Render(player.GetPosition());

		timeManager.PrintFPS();
		
		bool closed = false;
		while(renderer.GetDisplay()->pollEvent(event))
		{
			if(event.type == Event::Closed)
			{
				renderer.GetDisplay()->close();
				renderer.DeleteRenderer();
				terrainManager.DeleteTerrainManager();
				closed = true;
				break;
			}
		}

		if(closed)
		{
			break;
		}

		timeManager.EndTimer();
	}
}

