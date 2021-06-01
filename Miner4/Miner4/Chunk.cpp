#include "Chunk.h"

Chunk::Chunk(Vector2i Position, int ChunkSize, int TileSize):
chunkSize(ChunkSize),
tileSize(TileSize),
position(Position),
chunkPosition(Position),
chunkVertices(Quads,0),
totalTiles(chunkSize * chunkSize)
{
	totalTiles = 0;
	tiles = new Tile* [chunkSize * chunkSize];

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

			VertexArray sharedVertices;

			if (o != 0)
			{
				if (o != chunkSize - 1)
				{
					{
						sharedVertices.append(tiles[(i * chunkSize) + o - 1]->GetVertex(1));
						sharedVertices.append(tiles[(i * chunkSize) + o - 1]->GetVertex(2));
					}
				}
			}

			Tile* chunkTile = new Tile(tilePosition, TileSize,sharedVertices);

			tiles[(i * chunkSize) + o] = chunkTile;
			totalTiles++;
			for (int j = 0; j < 4; j++)
			{
				chunkVertices.append(chunkTile->GetVertex(j));
				totalVertices++;
			}
		}
	}
}


void Chunk::Update(Player& Player)
{
	for(int i = 0; i < totalTiles;i++)
	{
		if(tiles[i] != nullptr)
		{
			bool collided = CheckRectCollision(Player.GetPosition(), tiles[i]->GetPosition(), tileSize);

			if (collided)
			{
				delete(tiles[i]);
				tiles[i] = nullptr;
				RemakeChunk();
			}
		}
	}
}

void Chunk::RemakeChunk()
{
	VertexArray tempVertices(Quads,0);
	for(int i = 0; i < chunkSize * chunkSize;i++)
	{
		if(tiles[i] != nullptr)
		{
			for(int o = 0; o < 4; o++)
			{
				tempVertices.append(tiles[i]->GetVertex(o));
			}
		}
	}
	chunkVertices.clear();
	chunkVertices = tempVertices;
}

void Chunk::DeleteChunk()
{
	for(int i = 0; i < chunkSize * chunkSize;i++)
	{
		delete(tiles[i]);
	}
}

bool Chunk::CheckRectCollision(Vector2f Pos1,Vector2i Pos2,int Size)
{
	if(Pos1.x + Size > Pos2.x && Pos1.x < Pos2.x + Size)
	{
		if (Pos1.y + Size > Pos2.y && Pos1.y < Pos2.y + Size)
		{
			return true;
		}
		return false;
	}
	return false;
}
