#include <OGL3D/Game/OGame.h>
#include <Windows.h>

OGame::OGame()
{
	m_graphicsEngine = std::make_unique<OGraphicsEngine>();
	GameDisplay = std::make_unique<OWindow>();

	GameDisplay->MakeCurrentContext();
}

OGame::~OGame()
{
}

void OGame::onCreate()
{
}

void OGame::onUpdate()
{
	m_graphicsEngine->clear(OVec4(255, 0, 0, 1));

	GameDisplay->Present(false);
}

void OGame::onQuit()
{
}

void OGame::run()
{
	onCreate();

	//While the game is running m 
	MSG msg = {};

	while (isRunning) 
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				isRunning = false;
				continue;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		onUpdate();
	}

	onQuit();
}

void OGame::quit()
{
	isRunning = false;
}


