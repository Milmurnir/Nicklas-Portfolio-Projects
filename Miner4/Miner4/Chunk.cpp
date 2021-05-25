#include "Chunk.h"
#include "TerrainManager.h"

Chunk::Chunk(Vector2i Position, int ChunkSize, int TileSize):
chunkSize(ChunkSize),
tileSize(TileSize),
position(Position),
chunkPosition(Position),
chunkVertices(Quads,4)
{
	tiles = new Tile * [chunkSize * chunkSize];

	for (int i = 0; i < chunkSize; i++)
	{
		int y = chunkSize * i;
		for (int o = 0; o < chunkSize; o++)
		{
			int x = chunkSize * o;
		}
	}

	int ChunkXPos = position.x * ChunkSize * TileSize;
	int ChunkYPos = position.y * ChunkSize * TileSize;

	position.x = ChunkXPos + ChunkSize * TileSize / 2;
	position.y = ChunkYPos + ChunkSize * TileSize / 2;

	for (int i = 0; i < ChunkSize; i++)
	{
		int y = i * TileSize + ChunkYPos;

		for (int o = 0; o < ChunkSize; o++)
		{
			int x = o * TileSize + ChunkXPos;

			Vector2i tilePosition = Vector2i(x, y);

			Color color;

			if(chunkPosition.x % 2)
			{
				color = Color::Red;
			}

			else
			{
				color = Color::Blue;
			}

			Tile* chunkTile = new Tile(tilePosition, TileSize,color,o);

			tiles[(i * chunkSize) + o] = chunkTile;

			for (int j = 0; j < 4; j++)
			{
				chunkVertices.append(chunkTile->GetVertex(j));
			}
		}
	}
}


void Chunk::Update()
{
	
}

void Chunk::DeleteChunk()
{
	for(int i = 0; i < chunkSize * chunkSize;i++)
	{
		delete(tiles[i]);
	}
}


