#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>
using namespace sf;

class Tile
{
public:
	Tile(Vector2i Position, int TileSize, VertexArray& sharedVertices);

	Vertex& GetVertex(int Index) { return vertices[Index]; }

	void DeleteTile();

	Vector2i GetPosition() { return position; }

private:

	Vector2i position;
	VertexArray vertices;
};

