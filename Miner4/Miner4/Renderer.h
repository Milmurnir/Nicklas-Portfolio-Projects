#pragma once
#include "TerrainManager.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Renderer
{
public:
	Renderer(TerrainManager& TerrainManager);

	void DeleteRenderer();

	void Render(Vector2f playerPos);

	RenderWindow* GetDisplay() { return display; }

private:

	TerrainManager* terrainManager;

	RenderWindow* display;
};

