#include "TerrainManager.h"
#include <iostream>

TerrainManager::TerrainManager(Player& Player,Mutex& Mutex):
mutex(&Mutex)
{
	int loopsXAxis = (VideoMode::getDesktopMode().width) / (chunkSize * tileSize);
	int loopsYAxis = (VideoMode::getDesktopMode().height) / (chunkSize * tileSize);

	screenLoops.x = loopsXAxis;
	screenLoops.y = loopsYAxis;

	player = &Player;

	for(int i = 0; i < loopsYAxis + loadOffset;i++)
	{
		vector<Chunk*> tempArray;
		for(int o = 0; o < loopsXAxis + loadOffset;o++)
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

	Vector2i playerChunkPosition = Vector2i(playerPosition.x / chunkSize / tileSize, playerPosition.y / chunkSize / tileSize);

	Vector2i startCoord = Vector2i(playerChunkPosition.x - screenLoops.x / 2 - loadOffset / 2, playerChunkPosition.y - screenLoops.y / 2 - loadOffset / 2);

	for (int i = 0; i < screenLoops.y + loadOffset; i++)
	{
		for (int o = 0; o < screenLoops.x + loadOffset; o++)
		{
			bool foundChunk = false;
			for (int j = 0; j < allChunks.size(); j++)
			{
				if (allChunks[j]->GetChunkCord() == startCoord)
				{
					chunkMap[i][o] = allChunks[j];
					foundChunk = true;
					break;
				}

				if(allChunks[j]->GetChunkCord() == playerChunkPosition)
				{
					allChunks[j]->Update(*player);
				}


			}
			if (!foundChunk)
			{
				Chunk* chunk = new Chunk(startCoord, chunkSize, tileSize);
				chunkMap[i][o] = chunk;
				allChunks.push_back(chunk);
			}

			startCoord.x += 1;
		}
		startCoord.y += 1;
		startCoord.x = playerChunkPosition.x - screenLoops.x / 2 - loadOffset / 2;
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


