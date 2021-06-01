#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <mutex>

#include "Tile.h"
#include "Player.h"

using namespace std;
using namespace sf;

class Chunk
{
public:
	Chunk(Vector2i Position,int ChunkSize,int TileSize);

	void Update(Player& Player);

	Vector2i GetChunkCord() { return chunkPosition; }

	Vector2i GetPosition() { return position; }

	VertexArray& GetVertices() { return chunkVertices; }

	int GetVertexCount() { return totalVertices; }

	void DeleteChunk();

	void RemakeChunk();

	int GetChunkSize() { return chunkSize; }

private:

	bool CheckRectCollision(Vector2f Pos1, Vector2i Pos2, int Size);

	Tile** tiles;
	int chunkSize;
	int tileSize;
	int totalTiles;
	int totalVertices;
	Vector2i position;
	Vector2i chunkPosition;
	VertexArray chunkVertices;
};

