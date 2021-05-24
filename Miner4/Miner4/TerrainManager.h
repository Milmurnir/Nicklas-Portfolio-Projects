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

	vector<vector<Chunk*>> GetChunkArray() { return chunkArray; }

private:

	vector<Chunk*> allChunks;

	vector<vector<Chunk*>> chunkArray;

	Player* player;

	int chunkSize = 64;
	int tileSize = 16;

	Vector2i screenLoops;
};

