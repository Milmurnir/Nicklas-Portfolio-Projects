#include "Renderer.h"



Renderer::Renderer(TerrainManager& TerrainManager):
terrainManager(&TerrainManager)
{
	display = new RenderWindow(VideoMode(1920, 1080), "Miner Game");
}

void Renderer::DeleteRenderer()
{
	delete(display);
}

void Renderer::Render(Vector2f playerPos)
{
	display->clear();

	for(int i = 0; i < terrainManager->GetChunkArray().size();i++)
	{
		for(int o = 0; o < terrainManager->GetChunkArray()[i].size();o++)
		{
			display->draw(terrainManager->GetChunkArray()[i][o]->GetChunkVertices());
		}
	}

	RectangleShape sh;

	sh.setFillColor(Color::Red);
	sh.setSize(Vector2f(10, 10));
	sh.setPosition(playerPos);
	display->draw(sh);

	display->display();
}
