#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class TextManager
{
public:
	Font font;

	TextManager()
	{
		if(!font.loadFromFile("arial.ttf"))
		{
		
		}
	}
};