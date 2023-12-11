#include <OGL3D/Game/OGame.h>
#include <Windows.h>

OGame::OGame()
{
	GameDisplay = std::unique_ptr<OWindow>(new OWindow());
}

OGame::~OGame()
{
}

void OGame::run()
{
	//While the game is running m 
	MSG msg;

	while (isRunning && !GameDisplay->isClosed()) 
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep(1);
	}
}

void OGame::quit()
{
	isRunning = false;
}


