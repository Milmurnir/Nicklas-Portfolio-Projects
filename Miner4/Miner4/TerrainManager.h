#pragma once
#include "SFML/Graphics.hpp"
#include "Chunk.h"
#include "Player.h"
#include <vector>

using namespace sf;
using namespace std;

class TerrainManager
{
public:
	TerrainManager(Player& Player);

	void Update();

	void DeleteTerrainManager();

	void SortAllChunks();

	vector<vector<Chunk*>> GetChunkMap() { return chunkMap; }

private:

	vector<Chunk*> allChunks;

	vector<vector<Chunk*>> chunkMap;

	Player* player;

	int chunkSize = 128;
	int tileSize = 8;

	Vector2i screenLoops;
};

