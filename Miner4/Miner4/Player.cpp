#include "Player.h"
#include "TimeManager.h"
#include <Windows.h>


Player::Player(TimeManager& TimeManager):
timeManager(&TimeManager),
position(500,500)
{
}

void Player::Update()
{
	if(GetKeyState('A') & 0x8000)
	{
		position.x -= movementSpeed * timeManager->GetDeltaTime();
	}

	if(GetKeyState('D') & 0x8000)
	{
		position.x += movementSpeed * timeManager->GetDeltaTime();
	}

	if (GetKeyState('W') & 0x8000)
	{
		position.y -= movementSpeed * timeManager->GetDeltaTime();
	}

	if (GetKeyState('S') & 0x8000)
	{
		position.y += movementSpeed * timeManager->GetDeltaTime();
	}
}
