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

void RenderThread(Renderer& Renderer, bool& Playing) { while(Playing)Renderer.HelpRenderer(); }

int main()
{
	View view(Vector2f(0,0),Vector2f(1920,1080));

	bool playing = true;

	Event event;

	TimeManager timeManager;

	Player player(timeManager);

	TerrainManager terrainManager(player);

	Renderer renderer(terrainManager);

	thread terrainThread(UpdateTerrain, ref(terrainManager),ref(playing));
	
	terrainThread.detach();
	
	thread renderThread(RenderThread, ref(renderer),ref(playing));
	renderThread.detach();

	while (playing)
	{
		timeManager.StartTimer();

		player.Update();

		view.setCenter(player.GetPosition());

		//terrainManager.Update();
		//renderer.HelpRenderer();
		renderer.GetDisplay()->setView(view);
		renderer.Render(player.GetPosition());

		timeManager.PrintFPS();
		
		while(renderer.GetDisplay()->pollEvent(event))
		{
			if(event.type == Event::Closed)
			{
				renderer.GetDisplay()->close();
						
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

	Time time = seconds(0.5f);
	sleep(time);
	renderer.DeleteRenderer();
	terrainManager.DeleteTerrainManager();
}

void UpdateTerrain(TerrainManager& TerrainManager,bool& Playing)
{
	while(Playing)
	{
		TerrainManager.Update();
	}
}
