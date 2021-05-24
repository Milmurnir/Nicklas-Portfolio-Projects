#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>
using namespace sf;

class Tile
{
public:
	Tile(Vector2i Position, int TileSize,Color Color,int Index);

	Vertex GetVertex(int Index) { return vertices[Index]; }

	void DeleteTile();

private:

	VertexArray vertices;
};

