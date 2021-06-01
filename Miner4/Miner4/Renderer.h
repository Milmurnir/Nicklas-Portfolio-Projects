#pragma once
#include "TerrainManager.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Renderer
{
public:
	Renderer(TerrainManager& TerrainManager,Mutex& mutex);

	void DeleteRenderer();

	void Render(Vector2f playerPos);

	RenderWindow* GetDisplay() { return display; }

	void DrawTerrain();

private:

	Mutex* mutex;

	VertexArray vertices;

	TerrainManager* terrainManager;

	RenderWindow* display;

};