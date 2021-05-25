#include "TerrainManager.h"
#include <iostream>

TerrainManager::TerrainManager(Player& Player)
{
	int loopsXAxis = (VideoMode::getDesktopMode().width * 1.2f) / (chunkSize * tileSize) + 1;
	int loopsYAxis = (VideoMode::getDesktopMode().height * 1.2f) / (chunkSize * tileSize);

	screenLoops.x = loopsXAxis;
	screenLoops.y = loopsYAxis;

	player = &Player;

	for(int i = 0; i < loopsYAxis;i++)
	{
		vector<Chunk*> tempArray;
		for(int o = 0; o < loopsXAxis;o++)
		{
			Chunk* chunk = new Chunk(Vector2i(o, i), chunkSize, tileSize);

			allChunks.push_back(chunk);
			tempArray.push_back(chunk);
		}
		chunkMap.push_back(tempArray);
	}
}

void TerrainManager::Update()
{
	Vector2f playerPosition = player->GetPosition();

	Vector2f playerChunkPosition = Vector2f(playerPosition.x / chunkSize / tileSize,playerPosition.y / chunkSize / tileSize);

	Vector2i startCoord = Vector2i(playerChunkPosition.x - screenLoops.x/2, playerChunkPosition.y - screenLoops.y/2);

	for(int i = 0; i < screenLoops.y;i++)
	{
		for(int o = 0; o < screenLoops.x;o++)
		{
			bool foundChunk = false;
			for(int j = 0; j < allChunks.size();j++)
			{
				if(allChunks[j]->GetChunkCord() == startCoord)
				{
					chunkMap[i][o] = allChunks[j];
					foundChunk = true;
					break;
				}
			}
			if(!foundChunk)
				{
				Chunk* chunk = new Chunk(startCoord, chunkSize, tileSize);
				chunkMap[i][o] = chunk;
				allChunks.push_back(chunk);
				}

			chunkMap[i][o]->Update();

			startCoord.x += 1;
		}
		startCoord.y += 1;
		startCoord.x = playerChunkPosition.x - screenLoops.x / 2;
	}
}

void TerrainManager::DeleteTerrainManager()
{
	for(int i = 0; i < allChunks.size();i++)
	{
		allChunks[i]->DeleteChunk();
		delete(allChunks[i]);
	}
}


