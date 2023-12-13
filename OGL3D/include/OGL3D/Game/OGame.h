#pragma once
#include <memory>
#include <OGL3D/Window/OWindow.h>
#include <OGL3D/Graphics/OGraphicsEngine.h>

class OWindow;
class OGraphicsEngine;

class OGame
{

public:

	OGame();
	~OGame();


	virtual void onCreate();
	virtual void onUpdate();
	virtual void onQuit();

	void run();
	void quit();

protected:

	bool isRunning = true;
	std::unique_ptr<OGraphicsEngine> m_graphicsEngine;
	std::unique_ptr<OWindow> GameDisplay;

};

