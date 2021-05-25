#include "Renderer.h"



Renderer::Renderer(TerrainManager& TerrainManager):
terrainManager(&TerrainManager),
vertices(Quads,4)
{
	display = new RenderWindow(VideoMode(1920, 1080), "Miner Game");
	display->setFramerateLimit(1200);
}

void Renderer::DeleteRenderer()
{
	delete(display);
}

void Renderer::Render(Vector2f playerPos)
{
	display->clear();

	display->draw(vertices);

	RectangleShape sh;

	sh.setFillColor(Color::Red);
	sh.setSize(Vector2f(10, 10));
	sh.setPosition(playerPos);
	display->draw(sh);

	display->display();
}


void Renderer::HelpRenderer()
{
	vector<vector<Chunk*>> chunkMap = terrainManager->GetChunkMap();
	VertexArray tempVertices(Quads,4);

	for (int i = 0; i < chunkMap.size(); i++)
	{
		for (int o = 0; o < chunkMap[i].size(); o++)
		{
			for(int j = 0; j < chunkMap[i][o]->GetVertices().getVertexCount();j++)
			{
				Vertex test = chunkMap[i][o]->GetVertices()[j];
				tempVertices.append(chunkMap[i][o]->GetVertices()[j]);
			}
		}
	}

	vertices = tempVertices;
}