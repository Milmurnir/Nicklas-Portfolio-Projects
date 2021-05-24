#include <SFML/Graphics.hpp>

#include "TerrainManager.h"

using namespace sf;

RenderWindow window(VideoMode(1920, 1080), "Miner");

int main()
{
	Event event;

	TerrainManager terrainManager;

	while (window.isOpen())
	{
		window.clear();

		terrainManager.Update(&window);
		//Render here

		window.display();


		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
			{
				window.close();
			}
		}
	}
}

