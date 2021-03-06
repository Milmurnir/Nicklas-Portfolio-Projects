#include "Tile.h"

Tile::Tile(Vector2i Position, int TileSize,VertexArray& sharedVertices) : 
position(Position)
{
	Color color = Color::Green;

	if(sharedVertices.getVertexCount() == 2)
	{
		Vertex v2;
		v2.position.x = Position.x + TileSize;
		v2.position.y = Position.y;
		v2.texCoords.x = Position.x;
		v2.texCoords.y = Position.y;
		v2.color = color;

		Vertex v3;
		v3.position.x = Position.x + TileSize;
		v3.position.y = Position.y + TileSize;
		v3.texCoords.x = Position.x;
		v3.texCoords.y = Position.y;
		v3.color = color;

		vertices.append(sharedVertices[0]);
		vertices.append(v2);
		vertices.append(v3);
		vertices.append(sharedVertices[1]);

	}

	else
	{
		Vertex v1;
		v1.position.x = Position.x;
		v1.position.y = Position.y;
		v1.texCoords.x = Position.x;
		v1.texCoords.y = Position.y;
		v1.color = color;


		Vertex v2;
		v2.position.x = Position.x + TileSize;
		v2.position.y = Position.y;
		v2.texCoords.x = Position.x;
		v2.texCoords.y = Position.y;
		v2.color = color;

		Vertex v3;
		v3.position.x = Position.x + TileSize;
		v3.position.y = Position.y + TileSize;
		v3.texCoords.x = Position.x;
		v3.texCoords.y = Position.y;
		v3.color = color;

		Vertex v4;
		v4.position.x = Position.x;
		v4.position.y = Position.y + TileSize;
		v4.texCoords.x = Position.x;
		v4.texCoords.y = Position.y;
		v4.color = color;

		vertices.append(v1);
		vertices.append(v2);
		vertices.append(v3);
		vertices.append(v4);
	}
}

void Tile::DeleteTile()
{

}
