#include "Renderer.h"
#include "Chunk.h"

Renderer::Renderer(TerrainManager& TerrainManager,Mutex& Mutex):
terrainManager(&TerrainManager),
vertices(Quads,4),
mutex(&Mutex)
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
	DrawTerrain();

	RectangleShape sh;

	sh.setFillColor(Color::Red);
	sh.setSize(Vector2f(10, 10));
	sh.setPosition(playerPos);
	display->draw(sh);

	display->display();
}

#define ber 4

void Renderer::DrawTerrain()
{
	vector<vector<Chunk*>> chunkMap = terrainManager->GetChunkMap();

	//vector<Chunk> c(chunkMap[0].size(), *chunkMap[0][0]);
	//
	//vector<vector<Chunk>> tempChunkMap(chunkMap.size(), c);
	//
	//for(int i = 0; i < chunkMap.size();i++)
	//{
	//	for (int o = 0; o < chunkMap[i].size(); o++)
	//	{
	//		c[o] = *chunkMap[i][o];
	//	}
	//
	//	tempChunkMap[i] = (c);
	//}

	//int numberOfVertices = tempChunkMap.size() * tempChunkMap[0].size() * tempChunkMap[0][0].GetChunkSize() * tempChunkMap[0][0].GetChunkSize() * 4;
	//int numCount = 0;
	//
	//VertexArray tempVertices(Quads, numberOfVertices);

	for (int i = 0; i < chunkMap.size(); i++)
	{
		for (int o = 0; o < chunkMap[i].size(); o++)
		{
			//VertexArray chunkVertices(Quads, 0);
			//
			//chunkVertices = ;

			display->draw(chunkMap[i][o]->GetVertices());

			//for (int j = 0; j < chunkVertices.getVertexCount(); j++)
			//{
			//	tempVertices[numCount] = chunkVertices[j];
			//	numCount++;
			//	//Somehow this gets out of range as the number of verts isnt equal to the tempVertex size
			//}
		}
	}
	//vertices = tempVertices;
}