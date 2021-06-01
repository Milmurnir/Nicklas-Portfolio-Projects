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
	TerrainManager(Player& Player, Mutex& Mutex);

	void Update();

	void DeleteTerrainManager();

	vector<vector<Chunk*>> GetChunkMap() { return chunkMap; }

private:

	vector<Chunk*> allChunks;

	vector<vector<Chunk*>> chunkMap;

	Player* player;

	int loadOffset = 6;
	
	int tileSize = 16;
	int chunkSize = 16;

	Mutex* mutex;

	Vector2i screenLoops;
};

