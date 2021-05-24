#pragma once
#include "SFML/Graphics.hpp"
#include "Chunk.h"

#include <vector>

using namespace sf;
using namespace std;

class TerrainManager
{
public:
	TerrainManager();

	void Update(RenderWindow* window);

	static TerrainManager& GetInstance() { static TerrainManager T; return T; }

	void EditMap(int Direction);

	void AddChunk(Chunk chunk);

private:

	vector<vector<Chunk*>> chunkArray;

	int chunkSize = 8;
	int tileSize = 10;
};

