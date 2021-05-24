#include <SFML/Graphics.hpp>
#include <thread>
#include <functional>
#include <ctime>

#include "TerrainManager.h"
#include "TimeManager.h"
#include "Player.h"
#include "Renderer.h"



using namespace std;
using namespace sf;

void UpdateTerrain(TerrainManager& TerrainManager, bool& Playing);


int main()
{
	bool playing = true;

	Event event;

	TimeManager timeManager;

	Player player(timeManager);

	TerrainManager terrainManager(player);

	Renderer renderer(terrainManager);

	thread terrainThread(UpdateTerrain, ref(terrainManager),ref(playing));
	terrainThread.detach();

	while (playing)
	{
		timeManager.StartTimer();

		player.Update();

		//terrainManager.Update();

		renderer.Render(player.GetPosition());

		timeManager.PrintFPS();
		
		while(renderer.GetDisplay()->pollEvent(event))
		{
			if(event.type == Event::Closed)
			{
				renderer.GetDisplay()->close();
				renderer.DeleteRenderer();				
				playing = false;
				break;
			}
		}

		if(!playing)
		{
			break;
		}

		timeManager.EndTimer();
	}

	Time time = seconds(0.1f);
	sleep(time);

	terrainManager.DeleteTerrainManager();
}

void UpdateTerrain(TerrainManager& TerrainManager,bool& Playing)
{
	while(Playing)
	{
		TerrainManager.Update();
	}
}
