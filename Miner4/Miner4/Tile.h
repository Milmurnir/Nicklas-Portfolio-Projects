#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>
using namespace sf;

class Tile
{
public:
	Tile(Vector2i Position, int TileSize);

	Vertex GetVertex(int Index) { return vertices[Index]; }

private:

	VertexArray vertices;
};

