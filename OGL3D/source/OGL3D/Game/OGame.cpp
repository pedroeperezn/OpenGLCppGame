#include <OGL3D/Game/OGame.h>
#include <Windows.h>

OGame::OGame()
{
	//game constructor creates a unique pointer to a graphics engine instance
	m_graphicsEngine = std::make_unique<OGraphicsEngine>();
	//unique pointer to a window instance
	GameDisplay = std::make_unique<OWindow>();

	//make current context the context of the OWindow
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
	//on update, change the color of the screen to red
	m_graphicsEngine->clear(OVec4(255, 0, 0, 1));

	//present screen
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


