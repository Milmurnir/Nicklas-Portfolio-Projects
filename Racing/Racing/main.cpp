#include <SFML/Graphics.hpp>
#include <ctime>

#include "TrackManager.h"
#include "Renderer.h"
#include "Player.h"
#include "CollisionManager.h"
#include "TextManager.h"
#include "InputManager.h"


using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Racing!");

	

	TrackManager trackManager;

	CollisionManager colManager;

	Player player;

	Renderer renderer(player,window);

	TextManager textManager;

	InputManager inputManager(window,trackManager);

	

	while(window.isOpen())
	{

		window.clear();
		
		View view(FloatRect(0, 0, 1920, 1080));


		/*
		if(!trackManager.placingPlayer)
		{
			view.setCenter(player.x, player.y);
		}
		*/
		

		inputManager.update();

		window.setView(view);

		renderer.draw(player.id, player.position.x, player.position.y, player.rotation);

		renderer.drawTrack(trackManager.outerTrackPoints,trackManager.innerTrackPoints);

		player.checkMovement(trackManager.placingPlayer);

		colManager.checkColPlayer(trackManager.innerTrackPoints,trackManager.outerTrackPoints,player,window);

		trackManager.placePlayerSpawn(player);

		window.display();

	}
}