#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"


using namespace sf;

class Chunk
{
public:
	Chunk(Vector2i Position,int ChunkSize,int TileSize);

	void Update();

	Vector2i GetChunkCord() { return chunkPosition; }

	Vector2i GetPosition() { return position; }

	VertexArray& GetVertices() { return chunkVertices; }

	void DeleteChunk();

private:

	Tile** tiles;
	int chunkSize;
	int tileSize;
	Vector2i position;
	Vector2i chunkPosition;
	VertexArray chunkVertices;
};

