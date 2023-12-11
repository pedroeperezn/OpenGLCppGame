#pragma once
#include <memory>
#include <OGL3D/Window/OWindow.h>

class OWindow;

class OGame
{

public:

	OGame();
	~OGame();

	void run();
	void quit();

protected:

	bool isRunning = true;
	std::unique_ptr<OWindow> GameDisplay;

};

