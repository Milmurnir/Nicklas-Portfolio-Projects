#include "TerrainManager.h"



TerrainManager::TerrainManager()
{
	int loopsXAxis = VideoMode::getDesktopMode().width / (chunkSize * tileSize);
	int loopsYAxis = VideoMode::getDesktopMode().height / (chunkSize * tileSize);


	for(int i = 0; i < loopsYAxis;i++)
	{
		vector<Chunk*> tempArray;
		for(int o = 0; o < loopsXAxis;o++)
		{
			tempArray.push_back(new Chunk(Vector2i(o, i), chunkSize, tileSize));
		}
		chunkArray.push_back(tempArray);
	}
}

void TerrainManager::Update(RenderWindow* window)
{
	for(int i = 0; i < chunkArray.size();i++)
	{
		for(int o = 0; o < chunkArray[i].size();o++)
		{
			chunkArray[i][o]->Update(window);
		}
	}
}

void TerrainManager::DeleteChunk(Chunk chunk)
{
}

void TerrainManager::EditMap(int Direction)
{
}

void TerrainManager::AddChunk(Chunk chunk)
{
}
